use crate::ast::*;

pub struct Parser {}

impl<'p> Token<'p> {
  fn str(&self) -> &'p str { std::str::from_utf8(self.piece).unwrap() }
}

#[parser_macros::lalr1(Prog)]
#[lex = r#"
priority = []

[lexical]
'int' = 'Int'
'return' = 'Return'
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

  #[rule = "Expr -> IntConst"]
  fn expr_int(i: Token) -> Expr { Expr::Int(i.str().parse().expect("failed to parse int const")) }
}