fn main() -> std::io::Result<()> {
  let path = std::env::args().nth(1).expect("usage: minidecaf <input path>");
  let input = std::fs::read_to_string(path).expect("failed to read input");
  minidecaf::run(&input, &mut std::io::stdout())
}