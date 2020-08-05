#include "chibi.h"

char user_input[10*1024*1024];
Token* token;
Function* func;

static void read_input(char *path) {
  // Open and read the file.
  FILE *fp = fopen(path, "r");
  if (!fp)
    cout << "cannot open " << path << endl;

  int filemax = 10 * 1024 * 1024;
  int size = fread(user_input, 1, 10*1024*1024-2, fp);
  if (!feof(fp))
    cout << "file too large" << endl;

  // Make sure that the string ends with "\n\0".
  if (size == 0 || user_input[size - 1] != '\n')
    user_input[size++] = '\n';
  user_input[size] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 2)
       cout << argv[0] << "invalid number of arguments" << endl;

    // Tokenize and parse.
    read_input(argv[1]);
    token = lexing();
    func = parsing();
    for (Function *fn = func; fn; fn = fn->next) {
        fn->stack_size = 256;
    }
    codegen();
    return 0;
}