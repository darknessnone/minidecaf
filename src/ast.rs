pub struct Prog<'a> {
  pub func: Func<'a>,
}

pub struct Func<'a> {
  pub name: &'a str,
  pub stmts: Vec<Stmt<'a>>,
}

pub enum Stmt<'a> {
  Empty,
  Ret(Expr<'a>),
  Def(&'a str, Option<Expr<'a>>),
  Expr(Expr<'a>),
  If(Expr<'a>, Block<'a>, Option<Block<'a>>),
  Block(Block<'a>),
  While(Expr<'a>, Block<'a>),
  DoWhile(Block<'a>, Expr<'a>),
  For {
    init: Option<Box<Stmt<'a>>>,
    cond: Option<Expr<'a>>,
    update: Option<Expr<'a>>,
    body: Block<'a>,
  },
  Continue,
  Break,
}

pub struct Block<'a>(pub Vec<Stmt<'a>>);

#[derive(Copy, Clone)]
pub enum UnaryOp { Neg, BNot, LNot }

#[derive(Copy, Clone)]
pub enum BinaryOp { Add, Sub, Mul, Div, Mod, Lt, Le, Ge, Gt, Eq, Ne, And, Or }

pub enum Expr<'a> {
  Int(i32),
  Unary(UnaryOp, Box<Expr<'a>>),
  Binary(BinaryOp, Box<Expr<'a>>, Box<Expr<'a>>),
  Var(&'a str),
  Assign(&'a str, Box<Expr<'a>>),
  Condition(Box<Expr<'a>>, Box<Expr<'a>>, Box<Expr<'a>>),
}