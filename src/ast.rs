pub struct Prog<'a> {
  pub func: Func<'a>,
}

pub struct Func<'a> {
  pub name: &'a str,
  pub stmt: Stmt<'a>,
}

pub enum Stmt<'a> {
  Ret(Expr),
  Def(&'a str, Expr),
}

#[derive(Copy, Clone)]
pub enum UnaryOp { Neg, BNot, LNot }

#[derive(Copy, Clone)]
pub enum BinaryOp { Add, Sub, Mul, Div, Lt, Le, Ge, Gt, Eq, Ne, And, Or }

pub enum Expr {
  Int(i32),
  Unary(UnaryOp, Box<Expr>),
  Binary(BinaryOp, Box<Expr>, Box<Expr>),
}