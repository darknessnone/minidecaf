use crate::ast::*;

pub struct IrProg<'a> {
  pub func: IrFunc<'a>,
}

pub struct IrFunc<'a> {
  pub name: &'a str,
  pub stmts: Vec<IrStmt>,
}

pub enum IrStmt {
  Ldc(i32),
  Unary(UnaryOp),
  Binary(BinaryOp),
  Ret,
}

pub fn ast2ir<'a>(p: &Prog<'a>) -> IrProg<'a> {
  IrProg { func: func(&p.func) }
}

fn func<'a>(f: &Func<'a>) -> IrFunc<'a> {
  let mut stmts = Vec::new();
  match &f.stmt {
    Stmt::Ret(e) => {
      expr(&mut stmts, e);
      stmts.push(IrStmt::Ret);
    }
    Stmt::Def(..) => {}
  }
  IrFunc { name: f.name, stmts }
}

fn expr(stmts: &mut Vec<IrStmt>, e: &Expr) {
  match e {
    Expr::Int(x) => stmts.push(IrStmt::Ldc(*x)),
    Expr::Unary(op, x) => {
      expr(stmts, x);
      stmts.push(IrStmt::Unary(*op));
    }
    Expr::Binary(op, l, r) => {
      expr(stmts, l);
      expr(stmts, r);
      stmts.push(IrStmt::Binary(*op));
    }
  }
}