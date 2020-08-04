use crate::ast::{*, UnaryOp::*, BinaryOp::*};

pub struct Parser {}

impl<'p> Token<'p> {
  fn str(&self) -> &'p str { std::str::from_utf8(self.piece).unwrap() }
}

#[parser_macros::lalr1(Prog)]
#[lex = r#"
priority = [
  { assoc = 'left', terms = ['Add', 'Sub'] },
  { assoc = 'left', terms = ['Mul', 'Div'] },
  { assoc = 'left', terms = ['Neg', 'BNot', 'LNot'] },
]

[lexical]
'int' = 'Int'
'return' = 'Return'
'\+' = 'Add'
'-' = 'Sub'
'\*' = 'Mul'
'/' = 'Div'
'~' = 'BNot'
'!' = 'LNot'
'=' = 'Assign'
';' = 'Semi' # short for semicolon
'\(' = 'LPar' # short for parenthesis
'\)' = 'RPar'
'\{' = 'LBrc' # short for brace
'\}' = 'RBrc'
'\s+' = '_Eps'
'\d+' = 'IntConst'
'[a-zA-Z]\w*' = 'Id'
'.' = '_Err'
"#]
impl<'p> Parser {
  #[rule = "Prog -> Func"]
  fn prog(func: Func<'p>) -> Prog<'p> { Prog { func } }

  #[rule = "Func -> Int Id LPar RPar LBrc Stmt RBrc"]
  fn func(_i: Token, name: Token, _lp: Token, _rp: Token, _lb: Token, stmt: Stmt<'p>, _rb: Token) -> Func<'p> {
    Func { name: name.str(), stmt }
  }

  #[rule = "Stmt -> Return Expr Semi"]
  fn stmt_ret(_r: Token, e: Expr, _s: Token) -> Stmt<'p> { Stmt::Ret(e) }
  #[rule = "Stmt -> Int Id Assign Expr Semi"]
  fn stmt_def(_i: Token, name: Token, _a: Token, e: Expr, _s: Token) -> Stmt<'p> { Stmt::Def(name.str(), e) }

  #[rule = "Expr -> LPar Expr RPar"]
  fn expr_par(_l: Token, e: Expr, _r: Token) -> Expr { e }
  #[rule = "Expr -> IntConst"]
  fn expr_int(i: Token) -> Expr { Expr::Int(i.str().parse().expect("failed to parse int const")) }
  #[rule = "Expr -> Sub Expr"]
  #[prec = "Neg"]
  fn expr_neg(_: Token, e: Expr) -> Expr { Expr::Unary(Neg, Box::new(e)) }
  #[rule = "Expr -> BNot Expr"]
  fn expr_bnot(_: Token, e: Expr) -> Expr { Expr::Unary(BNot, Box::new(e)) }
  #[rule = "Expr -> LNot Expr"]
  fn expr_lnot(_: Token, e: Expr) -> Expr { Expr::Unary(LNot, Box::new(e)) }
  #[rule = "Expr -> Expr Add Expr"]
  fn expr_add(l: Expr, _: Token, r: Expr) -> Expr { Expr::Binary(Add, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Sub Expr"]
  fn expr_sub(l: Expr, _: Token, r: Expr) -> Expr { Expr::Binary(Sub, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Mul Expr"]
  fn expr_mul(l: Expr, _: Token, r: Expr) -> Expr { Expr::Binary(Mul, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Div Expr"]
  fn expr_div(l: Expr, _: Token, r: Expr) -> Expr { Expr::Binary(Div, Box::new(l), Box::new(r)) }
}