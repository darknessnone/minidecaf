#include "chibi.h"

void gen_node(Node *node) {
  switch (node->kind) {
    case ND_RETURN:
        printf("  mov rax, %ld\n", node->val);
        return;
    default:
        assert(false);
    }
}

void gen_text(Function* func) {
  printf(".text\n");

  for (Function *fn = func; fn; fn = fn->next) {
    printf(".global %s\n", fn->name);
    printf("%s:\n", fn->name);

    // Prologue
    printf("  push rbp\n");
    printf("  mov rbp, rsp\n");
    printf("  sub rsp, %d\n", fn->stack_size);

    // Emit code
    for (Node *node = fn->node; node; node = node->next)
      gen_node(node);

    // Epilogue
    printf("  mov rsp, rbp\n");
    printf("  pop rbp\n");
    printf("  ret\n");
  }
}

void code_gen() {
    gen_text(func);
}