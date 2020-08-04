use crate::ast::{*, UnaryOp::*, BinaryOp::*};

pub struct Parser {}

impl<'p> Token<'p> {
  fn str(&self) -> &'p str { std::str::from_utf8(self.piece).unwrap() }
}

fn mk_block(s: Stmt) -> Block { match s { Stmt::Block(x) => x, _ => Block(vec![s]) } }

#[parser_macros::lalr1(Prog)]
#[lex = r#"
priority = [
  { assoc = 'right', terms = ['Assign'] },
  { assoc = 'right', terms = ['Question'] },
  { assoc = 'left', terms = ['Or'] },
  { assoc = 'left', terms = ['And'] },
  { assoc = 'left', terms = ['Eq', 'Ne'] },
  { assoc = 'left', terms = ['Le', 'Ge', 'Lt', 'Gt'] },
  { assoc = 'left', terms = ['Add', 'Sub'] },
  { assoc = 'left', terms = ['Mul', 'Div'] },
  { assoc = 'left', terms = ['BNot', 'LNot'] },
  { assoc = 'left', terms = ['Else'] },
]

[lexical]
'int' = 'Int'
'return' = 'Return'
'if' = 'If'
'else' = 'Else'
'\+' = 'Add'
'-' = 'Sub'
'\*' = 'Mul'
'/' = 'Div'
'<' = 'Lt'
'<=' = 'Le'
'>=' = 'Ge'
'>' = 'Gt'
'==' = 'Eq'
'!=' = 'Ne'
'&&' = 'And'
'\|\|' = 'Or'
'~' = 'BNot'
'!' = 'LNot'
'=' = 'Assign'
'\?' = 'Question'
':' = 'Colon'
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

  #[rule = "Func -> Int Id LPar RPar LBrc StmtList RBrc"]
  fn func(_i: Token, name: Token, _lp: Token, _rp: Token, _lb: Token, stmts: Vec<Stmt<'p>>, _rb: Token) -> Func<'p> {
    Func { name: name.str(), stmts }
  }

  #[rule = "StmtList ->"]
  fn stmt_list0() -> Vec<Stmt<'p>> { Vec::new() }
  #[rule = "StmtList -> StmtList Stmt"]
  fn stmt_list1(mut l: Vec<Stmt<'p>>, r: Stmt<'p>) -> Vec<Stmt<'p>> { (l.push(r), l).1 }

  #[rule = "Stmt -> Return Expr Semi"]
  fn stmt_ret(_r: Token, e: Expr<'p>, _s: Token) -> Stmt<'p> { Stmt::Ret(e) }
  #[rule = "Stmt -> Int Id Semi"]
  fn stmt_def0(_i: Token, name: Token, _s: Token) -> Stmt<'p> { Stmt::Def(name.str(), None) }
  #[rule = "Stmt -> Int Id Assign Expr Semi"]
  fn stmt_def1(_i: Token, name: Token, _a: Token, e: Expr<'p>, _s: Token) -> Stmt<'p> { Stmt::Def(name.str(), Some(e)) }
  #[rule = "Stmt -> Expr Semi"]
  fn stmt_expr(e: Expr<'p>, _s: Token) -> Stmt<'p> { Stmt::Expr(e) }
  #[rule = "Stmt -> If LPar Expr RPar Stmt MaybeElse"]
  fn stmt_if(_i: Token, _l: Token, cond: Expr<'p>, _r: Token, t: Stmt<'p>, f: Option<Block<'p>>) -> Stmt<'p> { Stmt::If(cond, mk_block(t), f) }
  #[rule = "Stmt -> LBrc StmtList RBrc"]
  fn stmt_block(_l: Token, stmts: Vec<Stmt<'p>>, _r: Token) -> Stmt<'p> { Stmt::Block(Block(stmts)) }

  #[rule = "MaybeElse ->"]
  #[prec = "BNot"]
  fn maybe_else0() -> Option<Block<'p>> { None }
  #[rule = "MaybeElse -> Else Stmt"]
  fn maybe_else1(_e: Token, s: Stmt<'p>) -> Option<Block<'p>> { Some(mk_block(s)) }

  #[rule = "Expr -> LPar Expr RPar"]
  fn expr_par(_l: Token, e: Expr<'p>, _r: Token) -> Expr<'p> { e }
  #[rule = "Expr -> IntConst"]
  fn expr_int(i: Token) -> Expr<'p> { Expr::Int(i.str().parse().expect("failed to parse int const")) }
  #[rule = "Expr -> Sub Expr"]
  #[prec = "BNot"]
  fn expr_neg(_: Token, e: Expr<'p>) -> Expr<'p> { Expr::Unary(Neg, Box::new(e)) }
  #[rule = "Expr -> BNot Expr"]
  fn expr_bnot(_: Token, e: Expr<'p>) -> Expr<'p> { Expr::Unary(BNot, Box::new(e)) }
  #[rule = "Expr -> LNot Expr"]
  fn expr_lnot(_: Token, e: Expr<'p>) -> Expr<'p> { Expr::Unary(LNot, Box::new(e)) }
  #[rule = "Expr -> Expr Add Expr"]
  fn expr_add(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Add, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Sub Expr"]
  fn expr_sub(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Sub, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Mul Expr"]
  fn expr_mul(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Mul, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Div Expr"]
  fn expr_div(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Div, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Lt Expr"]
  fn expr_lt(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Lt, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Le Expr"]
  fn expr_le(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Le, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Ge Expr"]
  fn expr_ge(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Ge, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Gt Expr"]
  fn expr_gt(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Gt, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Eq Expr"]
  fn expr_eq(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Eq, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Ne Expr"]
  fn expr_ne(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Ne, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr And Expr"]
  fn expr_and(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(And, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Expr Or Expr"]
  fn expr_or(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Or, Box::new(l), Box::new(r)) }
  #[rule = "Expr -> Id"]
  fn expr_var(name: Token) -> Expr<'p> { Expr::Var(name.str()) }
  #[rule = "Expr -> Id Assign Expr"]
  fn expr_assign(name: Token, _a: Token, r: Expr<'p>) -> Expr<'p> { Expr::Assign(name.str(), Box::new(r)) }
  #[rule = "Expr -> Expr Question Expr Colon Expr"]
  #[prec = "Question"]
  fn expr_condition(cond: Expr<'p>, _q: Token, t: Expr<'p>, _c: Token, f: Expr<'p>) -> Expr<'p> { Expr::Condition(Box::new(cond), Box::new(t), Box::new(f)) }
}