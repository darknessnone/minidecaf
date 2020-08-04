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
  Pop,
  Ret,
}

pub fn ast2ir<'a>(p: &mut Prog<'a>) -> IrProg<'a> {
  IrProg { func: func(&mut p.func) }
}

struct NameStk<'a>(Vec<HashMap<&'a str, usize>>);

impl NameStk<'_> {
  fn lookup(&self, name: &str) -> usize {
    for map in self.0.iter().rev() {
      if let Some(x) = map.get(name) { return *x; }
    }
    panic!("variable `{}` not defined in current context", name)
  }
}

fn func<'a>(f: &mut Func<'a>) -> IrFunc<'a> {
  let (mut stk, mut var_cnt) = (NameStk(vec![HashMap::new()]), 0);
  let mut stmts = Vec::new();
  for s in &f.stmts {
    match s {
      Stmt::Ret(e) => {
        expr(&mut stmts, &stk, e);
        stmts.push(IrStmt::Ret);
      }
      Stmt::Def(name, init) => {
        if stk.0.last_mut().unwrap().insert(*name, var_cnt).is_some() {
          panic!("variable `{}` redefined in current context", name)
        }
        if let Some(x) = init {
          expr(&mut stmts, &stk, x);
          stmts.push(IrStmt::Store(var_cnt));
        }
        var_cnt += 1;
      }
      Stmt::Expr(e) => {
        expr(&mut stmts, &stk, e);
        stmts.push(IrStmt::Pop);
      }
    }
  }
  match stmts.last() {
    Some(IrStmt::Ret) => {}
    _ => {
      stmts.push(IrStmt::Ldc(0));
      stmts.push(IrStmt::Ret);
    }
  }
  IrFunc { name: f.name, var_cnt, stmts }
}

fn expr(stmts: &mut Vec<IrStmt>, stk: &NameStk, e: &Expr) {
  match e {
    Expr::Int(x) => stmts.push(IrStmt::Ldc(*x)),
    Expr::Unary(op, x) => {
      expr(stmts, stk, x);
      stmts.push(IrStmt::Unary(*op));
    }
    Expr::Binary(op, l, r) => {
      expr(stmts, stk, l);
      expr(stmts, stk, r);
      stmts.push(IrStmt::Binary(*op));
    }
    Expr::Var(name) => stmts.push(IrStmt::Load(stk.lookup(name))),
    Expr::Assign(name, r) => {
      expr(stmts, stk, r);
      let id = stk.lookup(name);
      stmts.push(IrStmt::Store(id));
      stmts.push(IrStmt::Load(id));
    }
  }
}