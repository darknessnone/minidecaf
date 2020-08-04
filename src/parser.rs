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
  { assoc = 'left', terms = ['Mul', 'Div', 'Mod'] },
  { assoc = 'left', terms = ['BNot', 'LNot'] },
  { assoc = 'left', terms = ['Else'] },
]

[lexical]
'int' = 'Int'
'return' = 'Return'
'if' = 'If'
'else' = 'Else'
'while' = 'While'
'for' = 'For'
'do' = 'Do'
'break' = 'Break'
'continue' = 'Continue'
'\+' = 'Add'
'-' = 'Sub'
'\*' = 'Mul'
'/' = 'Div'
'%' = 'Mod'
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
',' = 'Comma'
'\s+' = '_Eps'
'\d+' = 'IntConst'
'[a-zA-Z]\w*' = 'Id'
'.' = '_Err'
"#]
impl<'p> Parser {
  #[rule = "Prog ->"]
  fn prog0() -> Prog<'p> { Prog { funcs: Vec::new(), globs: Vec::new() } }
  #[rule = "Prog -> Prog Func"]
  fn prog_func(mut l: Prog<'p>, f: Func<'p>) -> Prog<'p> { (l.funcs.push(f), l).1 }
  #[rule = "Prog -> Prog Int Id Semi"]
  fn prog_glob0(mut l: Prog<'p>, _i: Token, name: Token, _s: Token) -> Prog<'p> { (l.globs.push((name.str(), None)), l).1 }
  #[rule = "Prog -> Prog Int Id Assign IntConst Semi"]
  fn prog_glob1(mut l: Prog<'p>, _i: Token, name: Token, _a: Token, init: Token, _s: Token) -> Prog<'p> {
    (l.globs.push((name.str(), Some(init.str().parse().expect("failed to parse int const")))), l).1
  }

  #[rule = "Func -> Int Id LPar ParamList RPar Semi"]
  fn func0(_i: Token, name: Token, _lp: Token, params: Vec<&'p str>, _rp: Token, _s: Token) -> Func<'p> { Func { name: name.str(), params, stmts: None } }
  #[rule = "Func -> Int Id LPar ParamList RPar LBrc StmtList RBrc"]
  fn func1(_i: Token, name: Token, _lp: Token, params: Vec<&'p str>, _rp: Token, _lb: Token, stmts: Vec<Stmt<'p>>, _rb: Token) -> Func<'p> {
    Func { name: name.str(), params, stmts: Some(stmts) }
  }

  #[rule = "ParamList ->"]
  fn param_list0() -> Vec<&'p str> { Vec::new() }
  #[rule = "ParamList -> ParamList1"]
  fn param_list1(x: Vec<&'p str>) -> Vec<&'p str> { x }
  #[rule = "ParamList1 -> Int Id"]
  fn param_list10(_i: Token, name: Token) -> Vec<&'p str> { vec![name.str()] }
  #[rule = "ParamList1 -> ParamList1 Comma Int Id"]
  fn param_list11(mut l: Vec<&'p str>, _c: Token, _i: Token, r: Token) -> Vec<&'p str> { (l.push(r.str()), l).1 }

  #[rule = "StmtList ->"]
  fn stmt_list0() -> Vec<Stmt<'p>> { Vec::new() }
  #[rule = "StmtList -> StmtList Stmt"]
  fn stmt_list1(mut l: Vec<Stmt<'p>>, r: Stmt<'p>) -> Vec<Stmt<'p>> { (l.push(r), l).1 }

  #[rule = "Stmt -> Semi"]
  fn stmt_empty(_s: Token) -> Stmt<'p> { Stmt::Empty }
  #[rule = "Stmt -> Return Expr Semi"]
  fn stmt_ret(_r: Token, e: Expr<'p>, _s: Token) -> Stmt<'p> { Stmt::Ret(e) }
  #[rule = "Stmt -> Int Id MaybeInit Semi"]
  fn stmt_def0(_i: Token, name: Token, init: Option<Expr<'p>>, _s: Token) -> Stmt<'p> { Stmt::Def(name.str(), init) }
  #[rule = "Stmt -> Expr Semi"]
  fn stmt_expr(e: Expr<'p>, _s: Token) -> Stmt<'p> { Stmt::Expr(e) }
  #[rule = "Stmt -> If LPar Expr RPar Stmt MaybeElse"]
  fn stmt_if(_i: Token, _l: Token, cond: Expr<'p>, _r: Token, t: Stmt<'p>, f: Option<Block<'p>>) -> Stmt<'p> { Stmt::If(cond, mk_block(t), f) }
  #[rule = "Stmt -> LBrc StmtList RBrc"]
  fn stmt_block(_l: Token, stmts: Vec<Stmt<'p>>, _r: Token) -> Stmt<'p> { Stmt::Block(Block(stmts)) }
  #[rule = "Stmt -> While LPar Expr RPar Stmt"]
  fn stmt_while(_w: Token, _l: Token, cond: Expr<'p>, _r: Token, body: Stmt<'p>) -> Stmt<'p> { Stmt::While(cond, mk_block(body)) }
  #[rule = "Stmt -> Do Stmt While LPar Expr RPar Semi"]
  fn stmt_do_while(_d: Token, body: Stmt<'p>, _w: Token, _l: Token, cond: Expr<'p>, _r: Token, _s: Token) -> Stmt<'p> { Stmt::DoWhile(mk_block(body), cond) }
  #[rule = "Stmt -> For LPar MaybeExpr Semi MaybeExpr Semi MaybeExpr RPar Stmt"]
  fn stmt_for0(_f: Token, _l: Token, init: Option<Expr<'p>>, _s1: Token, cond: Option<Expr<'p>>, _s2: Token, update: Option<Expr<'p>>, _r: Token, body: Stmt<'p>) -> Stmt<'p> {
    Stmt::For { init: init.map(|x| Box::new(Stmt::Expr(x))), cond, update, body: mk_block(body) }
  }
  #[rule = "Stmt -> For LPar Int Id MaybeInit Semi MaybeExpr Semi MaybeExpr RPar Stmt"]
  fn stmt_for1(_f: Token, _l: Token, _i: Token, name: Token, init: Option<Expr<'p>>, _s1: Token, cond: Option<Expr<'p>>, _s2: Token, update: Option<Expr<'p>>, _r: Token, body: Stmt<'p>) -> Stmt<'p> {
    Stmt::For { init: Some(Box::new(Stmt::Def(name.str(), init))), cond, update, body: mk_block(body) }
  }
  #[rule = "Stmt -> Break Semi"]
  fn stmt_break(_b: Token, _s: Token) -> Stmt<'p> { Stmt::Break }
  #[rule = "Stmt -> Continue Semi"]
  fn stmt_continue(_c: Token, _s: Token) -> Stmt<'p> { Stmt::Continue }

  #[rule = "MaybeInit ->"]
  fn maybe_init0() -> Option<Expr<'p>> { None }
  #[rule = "MaybeInit -> Assign Expr"]
  fn maybe_init1(_a: Token, e: Expr<'p>) -> Option<Expr<'p>> { Some(e) }

  #[rule = "MaybeElse ->"]
  #[prec = "BNot"]
  fn maybe_else0() -> Option<Block<'p>> { None }
  #[rule = "MaybeElse -> Else Stmt"]
  fn maybe_else1(_e: Token, s: Stmt<'p>) -> Option<Block<'p>> { Some(mk_block(s)) }

  #[rule = "MaybeExpr ->"]
  fn maybe_expr0() -> Option<Expr<'p>> { None }
  #[rule = "MaybeExpr -> Expr"]
  fn maybe_expr1(e: Expr<'p>) -> Option<Expr<'p>> { Some(e) }

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
  #[rule = "Expr -> Expr Mod Expr"]
  fn expr_mod(l: Expr<'p>, _: Token, r: Expr<'p>) -> Expr<'p> { Expr::Binary(Mod, Box::new(l), Box::new(r)) }
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
  #[rule = "Expr -> Id LPar ArgList RPar"]
  fn expr_call(name: Token, _l: Token, args: Vec<Expr<'p>>, _r: Token) -> Expr<'p> { Expr::Call(name.str(), args) }

  #[rule = "ArgList ->"]
  fn arg_list0() -> Vec<Expr<'p>> { Vec::new() }
  #[rule = "ArgList -> ArgList1"]
  fn arg_list1(x: Vec<Expr<'p>>) -> Vec<Expr<'p>> { x }
  #[rule = "ArgList1 -> Expr"]
  fn arg_list10(e: Expr<'p>) -> Vec<Expr<'p>> { vec![e] }
  #[rule = "ArgList1 -> ArgList1 Comma Expr"]
  fn arg_list11(mut l: Vec<Expr<'p>>, _c: Token, r: Expr<'p>) -> Vec<Expr<'p>> { (l.push(r), l).1 }
}