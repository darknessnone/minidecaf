use std::collections::{HashMap, hash_map::Entry};
use crate::ast::*;

pub struct IrProg<'a> {
  pub funcs: Vec<IrFunc<'a>>,
  pub globs: Vec<(&'a str, Vec<i32>)>,
}

pub struct IrFunc<'a> {
  pub name: &'a str,
  pub param_cnt: usize,
  pub var_cnt: usize,
  pub is_decl: bool,
  pub stmts: Vec<IrStmt>,
}

pub enum IrStmt {
  Ldc(i32),
  Unary(UnaryOp),
  Binary(BinaryOp),
  LocalAddr(usize),
  GlobalAddr(usize),
  Load,
  Store,
  Label(usize),
  Bz(usize),
  Bnz(usize),
  Jump(usize),
  Call(usize),
  Pop,
  Ret,
}

pub fn ast2ir<'a>(p: &'a Prog<'a>) -> IrProg<'a> {
  let mut glob2id = HashMap::new();
  let mut globs = Vec::new();
  for g in &p.globs {
    let id = globs.len();
    if glob2id.insert(g.name, (id, g)).is_some() { panic!("global variable `{}` redefined in current context", g.name); }
    let init = g.init.as_ref().map(|x| if let Expr::Int(i) = x { vec![*i] } else {
      panic!("global variable `{}` must be initialized with int consy", g.name)
    }).unwrap_or(vec![0; g.dims.iter().product::<u32>() as usize]);
    globs.push((g.name, init));
  }
  let mut func2id = HashMap::new();
  let mut funcs = Vec::new();
  for f in &p.funcs {
    match func2id.entry(f.name) {
      Entry::Vacant(v) => {
        v.insert(funcs.len());
        funcs.push(func(&func2id, &glob2id, f));
      }
      Entry::Occupied(o) => {
        let old = &mut funcs[*o.get()];
        if old.is_decl { *old = func(&func2id, &glob2id, f); } else if f.stmts.is_some() {
          panic!("function `{}` redefined in current context", f.name)
        }
      }
    }
  }
  IrProg { funcs, globs }
}

type SymbolMap<'a> = HashMap<&'a str, (usize, &'a VarDef<'a>)>;

struct FuncCtx<'a, 'b> {
  names: Vec<SymbolMap<'a>>,
  stmts: Vec<IrStmt>,
  loops: Vec<(usize, usize)>,
  func2id: &'b HashMap<&'a str, usize>,
  glob2id: &'b SymbolMap<'a>,
  var_cnt: usize,
  label_cnt: usize,
}

impl<'a> FuncCtx<'a, '_> {
  fn new_label(&mut self) -> usize { (self.label_cnt, self.label_cnt += 1).0 }

  fn lookup(&self, name: &str) -> (bool, (usize, &'a VarDef<'a>)) {
    for map in self.names.iter().rev() {
      if let Some(x) = map.get(name) { return (false, *x); }
    }
    if let Some(x) = self.glob2id.get(name) { return (true, *x); }
    panic!("variable `{}` not defined in current context", name)
  }
}

fn func<'a>(func2id: &HashMap<&str, usize>, glob2id: &SymbolMap<'a>, f: &Func<'a>) -> IrFunc<'a> {
  let mut ctx = FuncCtx { names: vec![HashMap::new()], stmts: Vec::new(), loops: Vec::new(), func2id, glob2id, var_cnt: 0, label_cnt: 0 };
  for d in &f.params { def(&mut ctx, d); }
  if let Some(stmts) = &f.stmts {
    for s in stmts { stmt(&mut ctx, s); }
    match ctx.stmts.last() {
      Some(IrStmt::Ret) => {}
      _ => {
        ctx.stmts.push(IrStmt::Ldc(0));
        ctx.stmts.push(IrStmt::Ret);
      }
    }
  }
  IrFunc { name: f.name, param_cnt: f.params.len(), var_cnt: ctx.var_cnt - f.params.len(), is_decl: f.stmts.is_none(), stmts: ctx.stmts }
}

fn block<'a, 'b>(ctx: &mut FuncCtx<'a, 'b>, b: &'a Block<'a>) {
  ctx.names.push(HashMap::new());
  for s in &b.0 { stmt(ctx, s); }
  ctx.names.pop();
}

fn def<'a, 'b>(ctx: &mut FuncCtx<'a, 'b>, d: &'a VarDef<'a>) {
  if ctx.names.last_mut().unwrap().insert(d.name, (ctx.var_cnt, d)).is_some() {
    panic!("variable `{}` redefined in current context", d.name)
  }
  if let Some(x) = &d.init {
    expr(ctx, x, true);
    ctx.stmts.push(IrStmt::LocalAddr(ctx.var_cnt));
    ctx.stmts.push(IrStmt::Store);
    ctx.stmts.push(IrStmt::Pop);
  }
  ctx.var_cnt += d.dims.iter().product::<u32>() as usize;
}

fn stmt<'a, 'b>(ctx: &mut FuncCtx<'a, 'b>, s: &'a Stmt<'a>) {
  match s {
    Stmt::Empty => {}
    Stmt::Ret(e) => {
      expr(ctx, e, true);
      ctx.stmts.push(IrStmt::Ret);
    }
    Stmt::Def(d) => def(ctx, d),
    Stmt::Expr(e) => {
      expr(ctx, e, true);
      ctx.stmts.push(IrStmt::Pop);
    }
    Stmt::If(cond, t, f) => {
      expr(ctx, cond, true);
      let (before_f, after_f) = (ctx.new_label(), ctx.new_label());
      ctx.stmts.push(IrStmt::Bz(before_f));
      block(ctx, t);
      ctx.stmts.push(IrStmt::Jump(after_f));
      ctx.stmts.push(IrStmt::Label(before_f));
      if let Some(f) = f { block(ctx, f); }
      ctx.stmts.push(IrStmt::Label(after_f));
    }
    Stmt::Block(b) => block(ctx, b),
    Stmt::While(cond, body) => {
      let (before_cond, after_body) = (ctx.new_label(), ctx.new_label());
      ctx.loops.push((after_body, before_cond));
      ctx.stmts.push(IrStmt::Label(before_cond));
      expr(ctx, cond, true);
      ctx.stmts.push(IrStmt::Bz(after_body));
      block(ctx, body);
      ctx.stmts.push(IrStmt::Jump(before_cond));
      ctx.stmts.push(IrStmt::Label(after_body));
      ctx.loops.pop();
    }
    Stmt::DoWhile(body, cond) => {
      let (before_body, before_cond, after_cond) = (ctx.new_label(), ctx.new_label(), ctx.new_label());
      ctx.loops.push((after_cond, before_cond));
      ctx.stmts.push(IrStmt::Label(before_body));
      block(ctx, body);
      ctx.stmts.push(IrStmt::Label(before_cond));
      expr(ctx, cond, true);
      ctx.stmts.push(IrStmt::Bnz(before_body));
      ctx.stmts.push(IrStmt::Label(after_cond));
      ctx.loops.pop();
    }
    Stmt::For { init, cond, update, body } => {
      ctx.names.push(HashMap::new());
      if let Some(init) = init { stmt(ctx, init); }
      let (before_cond, before_update, after_body) = (ctx.new_label(), ctx.new_label(), ctx.new_label());
      ctx.loops.push((after_body, before_update));
      ctx.stmts.push(IrStmt::Label(before_cond));
      expr(ctx, cond.as_ref().unwrap_or(&Expr::Int(1)), true);
      ctx.stmts.push(IrStmt::Bz(after_body));
      block(ctx, body);
      ctx.stmts.push(IrStmt::Label(before_update));
      if let Some(update) = update { expr(ctx, update, true); }
      ctx.stmts.push(IrStmt::Jump(before_cond));
      ctx.stmts.push(IrStmt::Label(after_body));
      ctx.loops.pop();
      ctx.names.pop();
    }
    Stmt::Break => ctx.stmts.push(IrStmt::Jump(ctx.loops.last().expect("break out of loop").0)),
    Stmt::Continue => ctx.stmts.push(IrStmt::Jump(ctx.loops.last().expect("continue out of loop").1)),
  }
}

fn ck_lvalue(e: &Expr) {
  match e { Expr::Var(..) | Expr::Index(..) | Expr::Deref(..) => {} _ => panic!("lvalue expression required in current context") }
}

fn expr(ctx: &mut FuncCtx, e: &Expr, load: bool) {
  match e {
    Expr::Int(x) => ctx.stmts.push(IrStmt::Ldc(*x)),
    Expr::Var(name) => {
      let (is_glob, (id, sym)) = ctx.lookup(name);
      ctx.stmts.push(if is_glob { IrStmt::GlobalAddr(id) } else { IrStmt::LocalAddr(id) });
      if load && sym.dims.is_empty() { ctx.stmts.push(IrStmt::Load); }
    }
    Expr::Index(arr, indices) => {
      expr(ctx, arr, true);
      let dims = match arr.as_ref() { Expr::Var(name) => (ctx.lookup(name).1).1.dims.as_slice(), _ => &[] };
      for (i, idx) in indices.iter().enumerate() {
        expr(ctx, idx, true);
        if i > dims.len() { ctx.stmts.push(IrStmt::Load); }
        let remain = dims.iter().skip(i + 1).product::<u32>() as i32;
        ctx.stmts.push(IrStmt::Ldc(remain * 8));
        ctx.stmts.push(IrStmt::Binary(BinaryOp::Mul));
        ctx.stmts.push(IrStmt::Binary(BinaryOp::Add));
      }
      if load && indices.len() >= dims.len() { ctx.stmts.push(IrStmt::Load); }
    }
    Expr::Deref(ptr) => {
      expr(ctx, ptr, true);
      if load { ctx.stmts.push(IrStmt::Load); }
    }
    Expr::Unary(op, x) => {
      expr(ctx, x, true);
      ctx.stmts.push(IrStmt::Unary(*op));
    }
    Expr::Binary(op, l, r) => {
      expr(ctx, l, true);
      expr(ctx, r, true);
      ctx.stmts.push(IrStmt::Binary(*op));
    }
    Expr::Assign(l, r) => {
      ck_lvalue(l);
      expr(ctx, r, true);
      expr(ctx, l, false);
      ctx.stmts.push(IrStmt::Store);
    }
    Expr::AddrOf(l) => {
      ck_lvalue(l);
      expr(ctx, l, false);
    }
    Expr::Condition(cond, t, f) => {
      expr(ctx, cond, true);
      let (before_f, after_f) = (ctx.new_label(), ctx.new_label());
      ctx.stmts.push(IrStmt::Bz(before_f));
      expr(ctx, t, true);
      ctx.stmts.push(IrStmt::Jump(after_f));
      ctx.stmts.push(IrStmt::Label(before_f));
      expr(ctx, f, true);
      ctx.stmts.push(IrStmt::Label(after_f));
    }
    Expr::Call(func, args) => {
      let id = *ctx.func2id.get(func).expect("function not defined in current context");
      for a in args { expr(ctx, a, true); }
      ctx.stmts.push(IrStmt::Call(id));
    }
  }
}