pub mod parser;
pub mod ast;
pub mod ir;
pub mod codegen;

use parser::{Parser, Lexer};
use std::io::{Result, Write};

pub fn run(input: &str, output: &mut impl Write) -> Result<()> {
  let p = Parser {}.parse(&mut Lexer::new(input.as_bytes())).expect("failed to parse input");
  let p = ir::ast2ir(&p);
  codegen::write_asm(&p, output)
}