#include "chibi.h"

static int labelseq = 0;
static char* func_name = NULL;

void gen_node(Node *node);

void gen_binary(Node* node) {
    gen_node(node->lexpr);
    gen_node(node->rexpr);
    printf("  pop rdi\n");
    printf("  pop rax\n");
    switch (node->kind) {
    case ND_ADD:
        printf("  add rax, rdi\n");
        break;
    case ND_SUB:
        printf("  sub rax, rdi\n");
        break;
    case ND_MUL:
        printf("  imul rax, rdi\n");
        break;
    case ND_DIV:
        printf("  cqo\n");
        printf("  idiv rdi\n");
        break;
    case ND_LT:
        printf("  cmp rax, rdi\n");
        printf("  setl al\n");
        printf("  movzb rax, al\n");
        break;        
    case ND_LTE:
        printf("  cmp rax, rdi\n");
        printf("  setle al\n");
        printf("  movzb rax, al\n");
        break;        
    case ND_EQ:
        printf("  cmp rax, rdi\n");
        printf("  sete al\n");
        printf("  movzb rax, al\n");
        break;        
    case ND_NEQ: 
        printf("  cmp rax, rdi\n");
        printf("  setne al\n");
        printf("  movzb rax, al\n");
        break;       
    }
    printf("  push rax\n");
}

void gen_addr(Node* node) {
    switch (node->kind) {
    case ND_VAR:
        printf("  lea rax, [rbp-%d]\n", node->var->offset);
        printf("  push rax\n");
        break;
    }
}

void store(Type* _ty) {
    printf("  pop rdi\n");
    printf("  pop rax\n");
    // sizeof(int) = 4
    printf("  mov [rax], edi\n");
    printf("  push rdi\n");
}

void load(Type* _ty) {
    printf("  pop rax\n");
    // sizeof(int) = 4
    printf("  movsxd rax, dword ptr [rax]\n");
    printf("  push rax\n");
}

void gen_node(Node *node) {
    int seq;
    Var* var;
    switch (node->kind) {
    case ND_RETURN:
        gen_node(node->lexpr);
        printf("  pop rax\n");
        printf("  jmp .L.return.%s\n", func_name);
        break;
    case ND_DECL:
        var = node->var;
        if(var->init) {
            gen_node(var->init);
            printf("  pop rax\n");
        }
        break;
    case ND_UNUSED_EXPR:
        gen_node(node->lexpr);
        printf("  pop rax\n");
        break;
    case ND_BLOCK:
        for (Node *n = node->body; n; n = n->next)
            gen_node(n);
        break;
    case ND_IF: 
        seq = labelseq++;
        if (node->els) {
            gen_node(node->cond);
            printf("  pop rax\n");
            printf("  cmp rax, 0\n");
            printf("  je  .L.else.%d\n", seq);
            gen_node(node->then);
            printf("  jmp .L.end.%d\n", seq);
            printf(".L.else.%d:\n", seq);
            gen_node(node->els);
            printf(".L.end.%d:\n", seq);
        } else {
            gen_node(node->cond);
            printf("  pop rax\n");
            printf("  cmp rax, 0\n");
            printf("  je  .L.end.%d\n", seq);
            gen_node(node->then);
            printf(".L.end.%d:\n", seq);
        }
        break;
    case ND_TERNARY:
        seq = labelseq++;
        gen_node(node->cond);
        printf("  pop rax\n");
        printf("  cmp rax, 0\n");
        printf("  je  .L.else.%d\n", seq);
        gen_node(node->then);
        printf("  jmp .L.end.%d\n", seq);
        printf(".L.else.%d:\n", seq);
        gen_node(node->els);
        printf(".L.end.%d:\n", seq);
        return;
    case ND_VAR:
        gen_addr(node);
        load(node->var->ty);
        break;
    case ND_ASSIGN:
        gen_addr(node->lexpr);
        gen_node(node->rexpr);
        store(node->lexpr->var->ty);
        break;
    case ND_NUM:
        printf("  mov rax, %ld\n", node->val);
        printf("  push rax\n");
        break;
    case ND_NOT:
        gen_node(node->lexpr);
        printf("  pop rax\n");
        printf("  cmp rax, 0\n");
        printf("  sete al\n");
        printf("  movzb rax, al\n");
        printf("  push rax\n");
        break;
    case ND_BITNOT:
        gen_node(node->lexpr);
        printf("  pop rax\n");
        printf("  not rax\n");
        printf("  push rax\n");
        break;
    case ND_NEG:
        gen_node(node->lexpr);
        printf("  pop rdi\n");
        printf("  xor rax, rax\n");
        printf("  sub rax, rdi\n");
        printf("  push rax\n");
        break;
    case ND_LOGAND: 
        seq = labelseq++;
        gen_node(node->lexpr);
        printf("  pop rax\n");
        printf("  cmp rax, 0\n");
        printf("  je  .L.false.%d\n", seq);
        gen_node(node->rexpr);
        printf("  pop rax\n");
        printf("  cmp rax, 0\n");
        printf("  je  .L.false.%d\n", seq);
        printf("  push 1\n");
        printf("  jmp .L.end.%d\n", seq);
        printf(".L.false.%d:\n", seq);
        printf("  push 0\n");
        printf(".L.end.%d:\n", seq);
        break;
    case ND_LOGOR: 
        seq = labelseq++;
        gen_node(node->lexpr);
        printf("  pop rax\n");
        printf("  cmp rax, 0\n");
        printf("  jne .L.true.%d\n", seq);
        gen_node(node->rexpr);
        printf("  pop rax\n");
        printf("  cmp rax, 0\n");
        printf("  jne .L.true.%d\n", seq);
        printf("  push 0\n");
        printf("  jmp .L.end.%d\n", seq);
        printf(".L.true.%d:\n", seq);
        printf("  push 1\n");
        printf(".L.end.%d:\n", seq);
        break;
    default:
        gen_binary(node);
        break;
    }
}

void gen_text(Function* func) {
    printf(".intel_syntax noprefix\n");
    printf(".text\n");

    for (Function *fn = func; fn; fn = fn->next) {
        printf(".global %s\n", fn->name);
        printf("%s:\n", fn->name);
        func_name = fn->name;
        // Prologue
        printf("  push rbp\n");
        printf("  mov rbp, rsp\n");
        printf("  sub rsp, %d\n", fn->stack_size);

        // Emit code
        for (Node *node = fn->node; node; node = node->next)
            gen_node(node);

        // Epilogue
        printf(".L.return.%s:\n", func_name);
        printf("  mov rsp, rbp\n");
        printf("  pop rbp\n");
        printf("  ret\n");
    }
}

void codegen() {
    gen_text(func);
}