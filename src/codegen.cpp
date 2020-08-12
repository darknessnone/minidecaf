#include "chibi.h"

static int labelseq = 0;
static char* func_name = NULL;
static int brkseq = 0;
static int contseq = 0;
static bool return_stmt = false;

static char *argreg[] = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};

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
    case ND_PTR_ADD:
        printf("  imul rdi, %d\n", node->ty->base->size);
        printf("  add rax, rdi\n");
        break;
    case ND_SUB:
        printf("  sub rax, rdi\n");
        break;
    case ND_PTR_SUB:
        printf("  imul rdi, %d\n", node->ty->base->size);
        printf("  sub rax, rdi\n");
        break;
    case ND_PTR_DIFF:
        printf("  sub rax, rdi\n");
        printf("  cqo\n");
        printf("  mov rdi, %d\n", node->lexpr->ty->base->size);
        printf("  idiv rdi\n");
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
        Var* var = node->var;
        if (var->is_local) {
            printf("  lea rax, [rbp-%d]\n", var->offset);
            printf("  push rax\n");
        } else {
            printf("  push offset %s\n", var->name);
        }
        break;
    }
}

void store(Type* _ty) {
    printf("  pop rdi\n");
    printf("  pop rax\n");
    // sizeof(long) = 8
    printf("  mov [rax], rdi\n");
    printf("  push rdi\n");
}

void load(Type* _ty) {
    printf("  pop rax\n");
    // sizeof(long) = 8
    printf("  movsxd rax, [rax]\n");
    printf("  push rax\n");
}

void gen_node(Node *node) {
    int seq, brk, cont, nargs;
    Var* var;
    switch (node->kind) {
    case ND_RETURN:
        gen_node(node->lexpr);
        printf("  pop rax\n");
        printf("  jmp .L.return.%s\n", func_name);
        return_stmt = true;
        break;
    case ND_DECL:
        var = node->var;
        if(var->init) {
            gen_node(var->init);
            printf("  pop rax\n");
        }
        break;
    case ND_UNUSED_EXPR:
        if(node->lexpr) {
            gen_node(node->lexpr);
            printf("  pop rax\n");
        }
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
    case ND_FOR:
        seq = labelseq++;
        brk = brkseq;
        cont = contseq;
        brkseq = contseq = seq;
        gen_node(node->init);
        printf(".L.begin.%d:\n", seq);
        if (node->cond) {
            gen_node(node->cond);
            printf("  pop rax\n");
            printf("  cmp rax, 0\n");
            printf("  je  .L.break.%d\n", seq);
        }
        gen_node(node->then);
        printf(".L.continue.%d:\n", seq);
        if (node->inc)
            gen_node(node->inc);
        printf("  jmp .L.begin.%d\n", seq);
        printf(".L.break.%d:\n", seq);
        brkseq = brk;
        contseq = cont;
        break;
    case ND_FUNC_CALL:
        nargs = 0;
        for (Node *arg = node->args; arg; arg = arg->next) {
            gen_node(arg);
            nargs++;
        }
        assert(nargs <= 6);
        for (int i = nargs - 1; i >= 0; i--)
            printf("  pop %s\n", argreg[i]);

        // We need to align %rsp to a 16 byte boundary before
        // calling a function because it is an ABI requirement.
        seq = labelseq++;
        printf("  mov rax, rsp\n");
        printf("  and rax, 15\n");
        printf("  jnz .L.call.%d\n", seq);
        printf("  call %s\n", node->func->name);
        printf("  jmp .L.end.%d\n", seq);
        printf(".L.call.%d:\n", seq);
        printf("  sub rsp, 8\n");
        printf("  call %s\n", node->func->name);
        printf("  add rsp, 8\n");
        printf(".L.end.%d:\n", seq);
        printf("  push rax\n");
        break;
    case ND_BREAK:
        printf("  jmp .L.break.%d\n", brkseq);
        break;
    case ND_CONTINUE:
        printf("  jmp .L.continue.%d\n", contseq);
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
    case ND_REF:
        gen_addr(node->lexpr);
        break;
    case ND_DEREF:
        gen_node(node->lexpr);
        // TODO check node->ty
        load(node->ty);
    return;
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

void load_arg(Var *var, int idx) {
    // static char *argreg4[] = {"edi", "esi", "edx", "ecx", "r8d", "r9d"};
    printf("  mov [rbp-%d], %s\n", var->offset, argreg[idx]);
}

void gen_data(Program *prog) {
    for (Var* var = prog->globals; var; var = var->next)
        printf(".global %s\n", var->name);

    printf("  .bss\n");

    for (Var* var = prog->globals; var; var = var->next) {
        if (var->init)
            continue;

        printf(".align %d\n", 4);
        printf("%s:\n", var->name);
        printf("  .zero %d\n", 4);
    }

    printf("  .data\n");

    for (Var* var = prog->globals; var; var = var->next) {
        if (!var->init)
            continue;

        printf(".align %d\n", 4);
        printf("%s:\n", var->name);
        printf("  .long %ld\n", var->init->val);
    }
}

void gen_text(Program* prog) {
    printf(".text\n");

    for (Function *fn = prog->functions; fn; fn = fn->next) {
        printf(".global %s\n", fn->name);
        printf("%s:\n", fn->name);
        func_name = fn->name;
        // Prologue
        printf("  push rbp\n");
        printf("  mov rbp, rsp\n");
        printf("  sub rsp, %d\n", fn->stack_size);

        // Push arguments to the stack
        int n = 0;
        for (Var *v = fn->arg; v; v = v->next)
            load_arg(v, n++);

        // Emit code
        for (Node *node = fn->node; node; node = node->next)
            gen_node(node);

        if(!return_stmt) {
            printf("  xor rax, rax\n");
        }

        // Epilogue
        printf(".L.return.%s:\n", func_name);
        printf("  mov rsp, rbp\n");
        printf("  pop rbp\n");
        printf("  ret\n");
    }
}

void codegen() {
    printf(".intel_syntax noprefix\n");
    gen_data(prog);
    gen_text(prog);
}