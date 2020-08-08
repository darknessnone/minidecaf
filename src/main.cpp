#include "chibi.h"

char user_input[10*1024*1024];
Token* token;
Function* func;
bool debug = false;

static void read_input(char *path) {
    // Open and read the file.
    FILE *fp = fopen(path, "r");
    if (!fp)
        printf("cannot open %s\n", path);

    int filemax = 10 * 1024 * 1024;
    int size = fread(user_input, 1, filemax-2, fp);
    if (!feof(fp))
        printf("file too large.\n");

    // Make sure that the string ends with "\n\0".
    if (size == 0 || user_input[size - 1] != '\n')
        user_input[size++] = '\n';
    user_input[size] = '\0';
}


int main(int argc, char **argv) {
    if (argc != 2)
       printf("invalid number of arguments\n");
    read_input(argv[1]);
    token = lexing();
    func = parsing();
    for (Function *fn = func; fn; fn = fn->next) {
        int offset = 8;
        for (Var *var = fn->arg; var; var = var->next) {
            var->offset = offset;
            offset += 4;
        }
        for (Var *var = fn->local; var; var = var->next) {
            var->offset = offset;
            offset += 4;
        }
        fn->stack_size = 256;
    }
    codegen();
    return 0;
}