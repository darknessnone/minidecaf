#include "chibi.h"

struct VarStack {
  VarStack *next;
  int depth;
  Var *var;
};

static int stack_depth = 0;
static Var* func_locals;
static VarStack *var_stack;

void push_stack() {
    stack_depth++;
}

void pop_stack() {
    stack_depth--;
    while(var_stack && var_stack->depth > stack_depth) {
        var_stack = var_stack->next;
    }
}

Node* new_node(NodeKind kind) {
    Node* node = new Node();
    node->kind = kind;
    node->ty = NULL;
    node->next = NULL;
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
    return expect_reserved("int");
}

bool parse_reserved(char* s) {
    if(!expect_reserved(s))
        return false;
    token = token->next;
    return true;
}

Type* parse_basetype() {
    Token* tok;
    if(!(tok = expect_basetype()))
        return NULL;
    token = token->next;
    // TODO: decide type through 'tok'
    Type *ty = &INT_TYPE;
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

Node* new_num(Token* tok) {
    Node* node = new_node(ND_NUM);
    node->ty = tok->ty;
    node->val = tok->val;
    return node;
}

Node* new_unary(NodeKind kind, Node *expr) {
    Node *node = new_node(kind);
    node->lexpr = expr;
    return node;
}

Node* new_binary(NodeKind kind, Node* lexpr, Node* rexpr) {
    Node *node = new_node(kind);
    node->lexpr = lexpr;
    node->rexpr = rexpr;
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
    return node;
}

Node* expr();

Node* num() {
    Token* tok = parse_num();
    assert(tok);
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
    return NULL;
}

Var* add_local(Var* var) {
    func_locals->next = var;
    func_locals = var;

    VarStack* vs = new VarStack();
    vs->next = var_stack;
    vs->depth = stack_depth;
    vs->var = var;
    var_stack = vs;

    return var;
} 

Node* var() {
    return find_local_var(parse_ident());
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
        return find_local_var(name);
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
    return primary();
}

Node* mul_div() {
    Node* node = unary();
    while(1) {
        if (parse_reserved("*"))
            node = new_binary(ND_MUL, node, unary());
        else if (parse_reserved("/"))
            node = new_binary(ND_DIV, node, unary());
        else 
            return node;
    }
}

Node* add_sub() {
    Node* node = mul_div();
    while(1) {
        if (parse_reserved("+"))
            node = new_binary(ND_ADD, node, mul_div());
        else if (parse_reserved("-"))
            node = new_binary(ND_SUB, node, mul_div());
        else 
            return node;
    }
}

Node* relational() {
    Node* node = add_sub();
    if (parse_reserved(">"))
        return new_binary(ND_LT, add_sub(), node);
    if (parse_reserved(">="))
        return new_binary(ND_LTE, add_sub(), node);
    if (parse_reserved("<"))
        return new_binary(ND_LT, node, add_sub());
    if (parse_reserved("<="))
        return new_binary(ND_LTE, node, add_sub());
    return node;
}

Node* equality() {
    Node* node = relational();
    if (parse_reserved("=="))
        return new_binary(ND_EQ, node, relational());
    if (parse_reserved("!="))
        return new_binary(ND_NEQ, node, relational());
    return node;
}

Node* logand() {
    Node* node = equality();
    while(1) {
        if (parse_reserved("&&"))
            node = new_binary(ND_LOGAND, node, equality());
        else 
            return node;
    }
}

Node* logor() {
    Node* node = logand();
    while(1) {
        if (parse_reserved("||"))
            node = new_binary(ND_LOGOR, node, logand());
        else 
            return node;
    }
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
    return tern;
}

Node* assign() {
    Node* node = ternary();
    if(parse_reserved("=")) {
        return new_binary(ND_ASSIGN, node, assign());
    }
    return node;
}

// declaration := basetype identifier ("=" lvar-initializer)? ";"
// lvar-initializer := exp

Node* declaration(Type* ty) {
    assert(ty);
    char* name = parse_ident();
    Var* var = new Var();
    var->name = name;
    var->init = NULL;
    var->ty = ty;
    var->next = NULL;
    add_local(var);
    if (parse_reserved("=")) {
        var->init = new_binary(ND_ASSIGN, new_var_node(var), expr());
    }
    assert(parse_reserved(";"));
    Node* node = new_stmt(ND_DECL, NULL);
    node->var = var;
    return node;
}

Node* expr() {
    return assign();
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
    // expr;
    node = new_node(ND_UNUSED_EXPR);
    node->lexpr = expr();
    assert(parse_reserved(";"));
    return node;
}

// step1

// <program> ::= <function>
// <function> ::= <type> <id> "(" ")" "{" <statement> "}"
// <type> ::= "int"
// <statement> ::= "return" <exp> ";"
// <exp> ::= <int>

// step2

// <exp> ::= <unary_op> <exp> | <int>
// <unary_op> ::= "!" | "~" | "-"

// step3

// <exp> ::= <exp> ("+" | "-") <exp> | <term>
// <term> ::= <term> ("*" | "/") <term> | <factor>
// <factor> ::= "(" <exp> ")" | <unary_op> <factor> | <int>

// step4

// <exp> ::= <logical-and-exp> { "||" <logical-and-exp> }
// <logical-and-exp> ::= <equality-exp> { "&&" <equality-exp> }
// <equality-exp> ::= <relational-exp> { ("!=" | "==") <relational-exp> }
// <relational-exp> ::= <additive-exp> { ("<" | ">" | "<=" | ">=") <additive-exp> }
// <additive-exp> ::= <term> { ("+" | "-") <term> }


// step 5

// <statement> ::= "return" <exp> ";"
//               | <exp> ";"
//               | "int" <id> [ = <exp> ] ";"

// step 6

// <statement> ::= "return" <exp> ";"
//               | <exp> ";"
//               | "int" <id> [ = <exp> ] ";"
//               | "if" "(" <exp> ")" <statement> [ "else" <statement> ]

// step 7

// <statement> ::= "return" <exp> ";"
//               | <exp> ";"
//               | "if" "(" <exp> ")" <statement> [ "else" <statement> ]
//               | "{" { <block-item> } "}

Function *parse_function() {
    Type *ty = parse_basetype();
    assert(ty);
    char *name = parse_ident();
    assert(name);

    Function *fn = new Function();
    fn->name = name;
    fn->ret_type = ty;


    var_stack = NULL;
    Var var_head = {};
    func_locals = &var_head;

    assert(stack_depth == 0);
    push_stack();
    assert(parse_reserved("("));
    // TODO: args
    assert(parse_reserved(")"));
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

Function* parsing() {
    Function head = {};
    Function *cur = &head;

    while (token->kind != TK_EOF) {
        Function *fn = parse_function();
        if (!fn)
            continue;
        cur->next = fn;
        cur = cur->next;
        continue;
    }

    return head.next;
}
