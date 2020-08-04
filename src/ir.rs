use std::collections::HashMap;
use crate::ast::*;

pub struct IrProg<'a> {
  pub func: IrFunc<'a>,
}

pub struct IrFunc<'a> {
  pub name: &'a str,
  pub var_cnt: usize,
  pub stmts: Vec<IrStmt>,
}

pub enum IrStmt {
  Ldc(i32),
  Unary(UnaryOp),
  Binary(BinaryOp),
  Load(usize),
  Store(usize),
  Label(usize),
  Bz(usize),
  Jump(usize),
  Pop,
  Ret,
}

pub fn ast2ir<'a>(p: &mut Prog<'a>) -> IrProg<'a> {
  IrProg { func: func(&mut p.func) }
}

#[derive(Default)]
struct FuncCtx<'a> {
  names: Vec<HashMap<&'a str, usize>>,
  stmts: Vec<IrStmt>,
  var_cnt: usize,
  label_cnt: usize,
}

impl FuncCtx<'_> {
  fn new_label(&mut self) -> usize { (self.label_cnt, self.label_cnt += 1).0 }

  fn lookup(&self, name: &str) -> usize {
    for map in self.names.iter().rev() {
      if let Some(x) = map.get(name) { return *x; }
    }
    panic!("variable `{}` not defined in current context", name)
  }
}

fn func<'a>(f: &mut Func<'a>) -> IrFunc<'a> {
  let mut ctx = FuncCtx::default();
  ctx.names.push(HashMap::new());
  for s in &f.stmts { stmt(&mut ctx, s); }
  match ctx.stmts.last() {
    Some(IrStmt::Ret) => {}
    _ => {
      ctx.stmts.push(IrStmt::Ldc(0));
      ctx.stmts.push(IrStmt::Ret);
    }
  }
  IrFunc { name: f.name, var_cnt: ctx.var_cnt, stmts: ctx.stmts }
}

fn stmt<'a>(ctx: &mut FuncCtx<'a>, s: &Stmt<'a>) {
  match s {
    Stmt::Ret(e) => {
      expr(ctx, e);
      ctx.stmts.push(IrStmt::Ret);
    }
    Stmt::Def(name, init) => {
      if ctx.names.last_mut().unwrap().insert(*name, ctx.var_cnt).is_some() {
        panic!("variable `{}` redefined in current context", name)
      }
      if let Some(x) = init {
        expr(ctx, x);
        ctx.stmts.push(IrStmt::Store(ctx.var_cnt));
      }
      ctx.var_cnt += 1;
    }
    Stmt::Expr(e) => {
      expr(ctx, e);
      ctx.stmts.push(IrStmt::Pop);
    }
    Stmt::If(cond, t, f) => {
      expr(ctx, cond);
      let (before_f, after_f) = (ctx.new_label(), ctx.new_label());
      ctx.stmts.push(IrStmt::Bz(before_f));
      stmt(ctx, t);
      ctx.stmts.push(IrStmt::Jump(after_f));
      ctx.stmts.push(IrStmt::Label(before_f));
      if let Some(f) = f { stmt(ctx, f); }
      ctx.stmts.push(IrStmt::Label(after_f));
    }
  }
}

fn expr(ctx: &mut FuncCtx, e: &Expr) {
  match e {
    Expr::Int(x) => ctx.stmts.push(IrStmt::Ldc(*x)),
    Expr::Unary(op, x) => {
      expr(ctx, x);
      ctx.stmts.push(IrStmt::Unary(*op));
    }
    Expr::Binary(op, l, r) => {
      expr(ctx, l);
      expr(ctx, r);
      ctx.stmts.push(IrStmt::Binary(*op));
    }
    Expr::Var(name) => ctx.stmts.push(IrStmt::Load(ctx.lookup(name))),
    Expr::Assign(name, r) => {
      expr(ctx, r);
      let id = ctx.lookup(name);
      ctx.stmts.push(IrStmt::Store(id));
      ctx.stmts.push(IrStmt::Load(id));
    }
    Expr::Condition(cond, t, f) => {
      expr(ctx, cond);
      let (before_f, after_f) = (ctx.new_label(), ctx.new_label());
      ctx.stmts.push(IrStmt::Bz(before_f));
      expr(ctx, t);
      ctx.stmts.push(IrStmt::Jump(after_f));
      ctx.stmts.push(IrStmt::Label(before_f));
      expr(ctx, f);
      ctx.stmts.push(IrStmt::Label(after_f));
    }
  }
}