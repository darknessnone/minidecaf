#include "chibi.h"

struct VarStack {
  VarStack *next;
  int depth;
  Var *var;
};

static int stack_depth = 0;
static Var* func_locals = NULL;
static VarStack *var_stack = NULL;
static Var* globals = NULL;

void push_stack() {
    stack_depth++;
}

void pop_stack() {
    stack_depth--;
    while(var_stack && var_stack->depth > stack_depth) {
        var_stack = var_stack->next;
    }
}

struct FuncList {
    FuncList* next;
    Function* func;
};

static FuncList* func_list = NULL;
static Function* hot_func = NULL;

Node* new_node(NodeKind kind) {
    Node* node = new Node();
    node->kind = kind;
    node->ty = NULL;
    node->next = NULL;
    node->cond = NULL;
    node->els = NULL;
    node->inc = NULL;
    node->init = NULL;
    node->lexpr = NULL;
    node->rexpr = NULL;
    node->then = NULL;
    node->var = NULL;
    return node;
}

Token* expect_reserved(char *s) {
    if (token->kind != TK_RESERVED || strlen(s) != token->len || strncmp(token->str, s, token->len))
        return NULL;
    return token;
}

Token* expect_ident() {
    if (token->kind != TK_IDENT)
        return NULL;
    return token;
}

Token* expect_int_literal() {
    if (token->kind != TK_NUM)
        return NULL;
    return token;
}

Token* expect_basetype() {
    Token* tok = NULL;
    if(tok = expect_reserved("int"))
        return tok;
    if(tok = expect_reserved("char"))
        return tok;
    if(tok = expect_reserved("short"))
        return tok;
    if(tok = expect_reserved("long"))
        return tok;
    return NULL;
}

bool parse_reserved(char* s) {
    if(!expect_reserved(s))
        return false;
    token = token->next;
    return true;
}

Type* parse_basetype() {
    Token* tok = NULL;
    Type* ty = NULL;
    if(tok = expect_reserved("int"))
        ty = &INT_TYPE;
    else if(tok = expect_reserved("char"))
        ty = &CHAR_TYPE;
    else if(tok = expect_reserved("short"))
        ty = &SHORT_TYPE;
    else if(tok = expect_reserved("long"))
        ty = &LONG_TYPE;
    if(ty)
        token = token->next;
    return ty;
}

Type* parse_type() {
    Type* ty = parse_basetype();
    if(!ty)
        return NULL;
    while(parse_reserved("*")) {
        ty = pointer_to(ty);
    }
    return ty;
}

char* parse_ident() {
    if(!expect_ident())
        return NULL;
    char* ident = new char[256];
    assert(token->len < 256);
    strncpy(ident, token->str, token->len);
    ident[token->len] = 0;
    token = token->next;
    return ident;
}

Token* parse_num() {
    Token* tok;
    if(!(tok = expect_int_literal()))
        return NULL;
    token = token->next;
    return tok;
}

bool is_func() {
    Token *tok = token;
    assert(parse_type());
    char *name = parse_ident();
    bool isfunc = name && parse_reserved("(");
    token = tok;
    return isfunc;
}

Node* new_num(Token* tok) {
    Node* node = new_node(ND_NUM);
    node->ty = tok->ty;
    node->val = tok->val;
    return node;
}

Node* new_unary(NodeKind kind, Node *expr) {
    Node *node = new_node(kind);
    node->lexpr = expr;
    switch (kind)
    {
    case ND_NOT:
    case ND_BITNOT:
    case ND_NEG: 
        node->ty = &LONG_TYPE;
        break;
    case ND_REF:
        assert(node->lexpr->ty);
        node->ty = pointer_to(node->lexpr->ty);
    case ND_DEREF:  
        assert(is_ptr(node->lexpr->ty));
        node->ty = node->lexpr->ty->base;
        break;
    }
    return node;
}

Node* new_binary(NodeKind kind, Node* lexpr, Node* rexpr, Type* ty) {
    Node *node = new_node(kind);
    node->lexpr = lexpr;
    node->rexpr = rexpr;
    node->ty = ty;
    return node;
}

Node* new_stmt(NodeKind kind, Node* expr) {
    Node *node = new_node(kind);
    node->lexpr = expr;
    return node;
}

Node* new_var_node(Var* var) {
    Node *node = new_node(ND_VAR);
    node->var = var;
    node->ty = var->ty;
    return node;
}

Node* new_unused(Node* expr) {
    Node *node = new_node(ND_UNUSED_EXPR);
    node->lexpr = expr;
    return node;
}

Var* new_var(char* name, Type* ty) {
    Var *var = new Var();
    var->name = name;
    var->ty = ty;
    var->init = NULL;
    var->next = NULL;
    var->is_local = false;
    return var;
}

Var* new_gvar(char *name, Type *ty) {
    Var* var = new_var(name, ty);
    var->next = globals;
    globals = var;
    return var;
}

Node* new_add(Node *lexpr, Node *rexpr) {
    if (is_integer(lexpr->ty) && is_integer(rexpr->ty))
        return new_binary(ND_ADD, lexpr, rexpr, &LONG_TYPE);
    if (is_ptr(lexpr->ty) && is_integer(rexpr->ty))
        return new_binary(ND_PTR_ADD, lexpr, rexpr, lexpr->ty);
    if (is_integer(lexpr->ty) && is_ptr(rexpr->ty))
        return new_binary(ND_PTR_ADD, rexpr, lexpr, rexpr->ty);
    return NULL;
}

Node* new_sub(Node *lexpr, Node *rexpr) {
    if (is_integer(lexpr->ty) && is_integer(rexpr->ty))
        return new_binary(ND_SUB, lexpr, rexpr, &LONG_TYPE);
    if (is_ptr(lexpr->ty) && is_integer(rexpr->ty))
        return new_binary(ND_PTR_SUB, lexpr, rexpr, lexpr->ty);
    if (is_ptr(lexpr->ty) && is_ptr(rexpr->ty))
        return new_binary(ND_PTR_DIFF, lexpr, rexpr, lexpr->ty);
    return NULL;
}

Node* expr();

Node* num() {
    Token* tok;
    if(!(tok = parse_num())) {
        return NULL;
    }
    Node* node = new_num(tok);
    return node;
}

Node* find_local_var(char* name) {
    int len = strnlen(name, 1000);
    for(VarStack* vs = var_stack; vs; vs = vs->next) {
        Var* var = vs->var;
        if(strnlen(var->name, 1000) == len && !strncmp(var->name, name, len))
            return new_var_node(var);
    }
    if(hot_func) {
        for(Var* var = hot_func->arg; var; var = var->next) {
            if(strnlen(var->name, 1000) == len && !strncmp(var->name, name, len))
                return new_var_node(var);
        }
    }
    return NULL;
}

Node* find_gvar(char* name) {
    int len = strnlen(name, 1000);
    for(Var* var = globals; var; var = var->next) {
        if(strnlen(var->name, 1000) == len && !strncmp(var->name, name, len))
            return new_var_node(var);
    }
    return NULL;
}

Node* find_var(char* name) {
    Node* var;
    if((var = find_local_var(name)))
        return var;
    return find_gvar(name);
}

Var* add_local(Var* var) {
    var->is_local = true;

    func_locals->next = var;
    func_locals = var;

    VarStack* vs = new VarStack();
    vs->next = var_stack;
    vs->depth = stack_depth;
    vs->var = var;
    var_stack = vs;

    return var;
} 

Function* find_func(char* name) {
    int len = strnlen(name, 1000);
    for(FuncList* fl = func_list; fl; fl = fl->next) {
        if(strnlen(fl->func->name, 1000) == len && !strncmp(fl->func->name, name, len))
            return fl->func;
    }
    return NULL;
}

Function* add_func(Function* func) {
    if(!find_func(func->name)) {
        FuncList* fl = new FuncList();
        fl->func = func;
        fl->next = func_list;
        func_list = fl;
    }
    return func;
}

Node* var() {
    return find_var(parse_ident());
}

Node* func_args(Function* fn) {
    if(parse_reserved(")"))
        return NULL;

    Node *head = expr();
    Node *cur = head;
    while (parse_reserved(",")) {
        cur->next = expr();
        cur = cur->next;
        cur->next = NULL;
    }
    assert(parse_reserved(")"));
    return head;
}

// primary = identifiers
//         | "(" expr ")"
//         | num

Node* primary() {
    if (parse_reserved("(")) {
        Node* pri = expr();
        parse_reserved(")");
        return pri;
    }
    char* name;
    if (name = parse_ident()) {
        Node* node;
        // function call
        if(parse_reserved("(")) {
            Node *node = new_node(ND_FUNC_CALL);
            node->func = find_func(name);
            assert(node->func);
            node->args = func_args(node->func);
            return node;
        }
        return find_var(name);
    }
    return num();
}

Node* unary() {
    if (parse_reserved("-"))
        return new_unary(ND_NEG, unary());
    if (parse_reserved("!"))
        return new_unary(ND_NOT, unary());
    if (parse_reserved("~"))
        return new_unary(ND_BITNOT, unary());
    if (parse_reserved("*"))
        return new_unary(ND_DEREF, unary());
    if (parse_reserved("&"))
        return new_unary(ND_REF, unary());
    return primary();
}

Node* mul_div() {
    Node* node = unary();
    while(1) {
        if (parse_reserved("*"))
            node = new_binary(ND_MUL, node, unary(), &LONG_TYPE);
        else if (parse_reserved("/"))
            node = new_binary(ND_DIV, node, unary(), &LONG_TYPE);
        else 
            break;
    }
    node->ty = &LONG_TYPE;
    return node;
}

Node* add_sub() {
    Node* node = mul_div();
    while(1) {
        if (parse_reserved("+"))
            node = new_add(node, mul_div());
        else if (parse_reserved("-"))
            node = new_sub(node, mul_div());
        else 
            return node;
    }
}

Node* relational() {
    Node* node = add_sub();
    if (parse_reserved(">"))
        return new_binary(ND_LT, add_sub(), node, &LONG_TYPE);
    if (parse_reserved(">="))
        return new_binary(ND_LTE, add_sub(), node, &LONG_TYPE);
    if (parse_reserved("<"))
        return new_binary(ND_LT, node, add_sub(), &LONG_TYPE);
    if (parse_reserved("<="))
        return new_binary(ND_LTE, node, add_sub(), &LONG_TYPE);
    return node;
}

Node* equality() {
    Node* node = relational();
    if (parse_reserved("=="))
        return new_binary(ND_EQ, node, relational(), &LONG_TYPE);
    if (parse_reserved("!="))
        return new_binary(ND_NEQ, node, relational(), &LONG_TYPE);
    return node;
}

Node* logand() {
    Node* node = equality();
    for(;parse_reserved("&&");) {
        node = new_binary(ND_LOGAND, node, equality(), &LONG_TYPE);
    }
    return node;
}

Node* logor() {
    Node* node = logand();
    for(;parse_reserved("||");){
        node = new_binary(ND_LOGOR, node, logand(), &LONG_TYPE);
    }
    return node;
}

Node* ternary() {
    Node *node = logor();
    if(!parse_reserved("?"))
        return node;

    Node *tern = new_node(ND_TERNARY);
    tern->cond = node;
    tern->then = expr();
    assert(parse_reserved(":"));
    tern->els = ternary();
    assert(tern->then->ty);
    tern->ty = tern->then->ty;
    return tern;
}

Node* assign() {
    Node* node = ternary();
    if(parse_reserved("=")) {
        return new_binary(ND_ASSIGN, node, assign(), node->ty);
    }
    return node;
}

// declaration := basetype identifier ("=" lvar-initializer)? ";"
// lvar-initializer := exp

Node* declaration(Type* ty) {
    assert(ty);
    char* name = parse_ident();
    Var* var = new_var(name, ty);
    add_local(var);
    if (parse_reserved("=")) {
        var->init = new_binary(ND_ASSIGN, new_var_node(var), expr(), ty);
    }
    assert(parse_reserved(";"));
    Node* node = new_stmt(ND_DECL, NULL);
    node->var = var;
    return node;
}

Node* expr() {
    Node* node = assign();
    assert(node->ty);
    return node;
}

Node* ginit() {
    Node* node = num();
    assert(node);
    return node;
}

Node* stmt() {
    Node* node = NULL;
    if (parse_reserved("return")) {
        Node* exp = expr();
        node = new_stmt(ND_RETURN, exp);
        assert(parse_reserved(";"));
        return node;
    }
    if (parse_reserved("if")) {
        assert(parse_reserved("("));
        node = new_node(ND_IF);
        node->cond = expr();
        assert(parse_reserved(")"));
        node->then = stmt();
        if(parse_reserved("else"))
            node->els = stmt();
        return node;
    }
    if (parse_reserved("for")) {
        Node *node = new_node(ND_FOR);
        parse_reserved("(");
        push_stack();
        node->init = stmt();
        if (!parse_reserved(";")) {
            node->cond = expr();
            assert(parse_reserved(";"));
        }
        if (!parse_reserved(")")) {
            node->inc = new_unused(expr());
            assert(parse_reserved(")"));
        }
        node->then = stmt();
        pop_stack();
        return node;
    }
    if (parse_reserved("break")) {
        assert(parse_reserved(";"));
        return new_node(ND_BREAK);
    }
    if (parse_reserved("continue")) {
        assert(parse_reserved(";"));
        return new_node(ND_CONTINUE);
    }
    // declaration
    Type* ty;
    if (ty = parse_basetype()) {
        return declaration(ty);
    }
    // { stmt* }
    if (parse_reserved("{")) {
        Node head = {};
        Node *cur = &head;

        push_stack();
        while (!parse_reserved("}")) {
            cur->next = stmt();
            cur = cur->next;
        }
        pop_stack();

        Node *node = new_node(ND_BLOCK);
        node->body = head.next;
        return node;
    }
    // expr ";"
    node = new_unused(expr());
    assert(parse_reserved(";"));
    return node;
}

Var* decl_func_arg() {
    Type* ty = parse_type();
    Var* var = new_var(parse_ident(), ty);
    var->is_local = true;
    return var;
}

Var* decl_func_args() {
    if (parse_reserved(")")) {
        return NULL;
    }

    Var* param = decl_func_arg();
    Var* cur = param;
    while (!parse_reserved(")")) {
        assert(parse_reserved(","));
        cur->next = decl_func_arg();
        cur = cur->next;
    }
    return param;
}

Function *parse_function() {
    Type *ty = parse_type();
    assert(ty);
    char *name = parse_ident();
    assert(name);

    Function *fn = new Function();
    fn->name = name;
    fn->ret_type = ty;
    fn->node = NULL;
    fn->next = NULL;

    var_stack = NULL;
    Var var_head = {};
    func_locals = &var_head;

    push_stack();
    assert(parse_reserved("("));

    fn->arg = decl_func_args();

    add_func(fn);

    if(parse_reserved(";"))
        return NULL;

    hot_func = fn;

    assert(parse_reserved("{"));

    // Read function body
    Node head = {};
    Node *cur = &head;
    while (!parse_reserved("}")) {
        cur->next = stmt();
        cur = cur->next;
    }
    pop_stack();
    fn->local = var_head.next;
    fn->node = head.next;
    return fn;
}

void global_var() {
    Type *ty = parse_type();
    char *name = parse_ident();

    Node* var;
    if(var = find_gvar(name)) {
        assert(var->var->init == NULL);
        if (parse_reserved("="))
            var->var->init = ginit();
    } else {
        Var *var = new_gvar(name, ty);
        if (parse_reserved("="))
            var->init = ginit();
    }
    assert(parse_reserved(";")); 
}

Program* parsing() {
    Function head = {};
    Function* cur = &head;
    while (token->kind != TK_EOF) {
        if(is_func()) {
            Function *fn = parse_function();
            if (!fn)
                continue;
            cur->next = fn;
            cur = fn;

            func_locals = NULL;
            var_stack = NULL;
            hot_func = NULL;

            continue;
        }
        global_var();
    }

    Program* program = new Program();
    program->functions = head.next;
    program->globals = globals;
    return program;
}
