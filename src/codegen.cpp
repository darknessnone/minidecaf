#include "chibi.h"

void gen_node(Node *node) {
  switch (node->kind) {
    case ND_RETURN:
        gen_node(node->expr);
        printf("  pop rax\n");
        break;
    case ND_NUM:
        printf("  mov rax, %ld\n", node->val);
        printf("  push rax\n");
        break;
    case ND_NOT:
        gen_node(node->expr);
        printf("  pop rax\n");
        printf("  cmp rax, 0\n");
        printf("  sete al\n");
        printf("  movzb rax, al\n");
        printf("  push rax\n");
        break;
    case ND_BITNOT:
        gen_node(node->expr);
        printf("  pop rax\n");
        printf("  not rax\n");
        printf("  push rax\n");
        break;
    case ND_NEG:
        gen_node(node->expr);
        printf("  pop rdi\n");
        printf("  xor rax, rax\n");
        printf("  sub rax, rdi\n");
        printf("  push rax\n");
        break;
    default:
        assert(false);
    }
}

void gen_text(Function* func) {
    printf(".intel_syntax noprefix\n");
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

void codegen() {
    gen_text(func);
}