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

pub enum Expr {
  Int(i32),
}