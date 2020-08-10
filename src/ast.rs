pub struct Prog<'a> {
  pub funcs: Vec<Func<'a>>,
  pub globs: Vec<VarDef<'a>>,
}

pub struct Func<'a> {
  pub name: &'a str,
  pub params: Vec<VarDef<'a>>,
  pub stmts: Option<Vec<Stmt<'a>>>,
}

pub struct VarDef<'a> {
  pub name: &'a str,
  pub dims: Vec<u32>,
  pub init: Option<Expr<'a>>,
}

pub enum Stmt<'a> {
  Empty,
  Ret(Expr<'a>),
  Def(VarDef<'a>),
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
  Var(&'a str),
  Index(Box<Expr<'a>>, Vec<Expr<'a>>),
  Deref(Box<Expr<'a>>),
  Unary(UnaryOp, Box<Expr<'a>>),
  Binary(BinaryOp, Box<Expr<'a>>, Box<Expr<'a>>),
  Assign(Box<Expr<'a>>, Box<Expr<'a>>),
  AddrOf(Box<Expr<'a>>),
  Condition(Box<Expr<'a>>, Box<Expr<'a>>, Box<Expr<'a>>),
  Call(&'a str, Vec<Expr<'a>>),
}