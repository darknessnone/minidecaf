#include "chibi.h"

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

bool parse_reserved(char* s) {
    if(!expect_reserved(s))
        return false;
    token = token->next;
    return true;
}

Type* parse_basetype() {
    if(!expect_reserved("int"))
        return NULL;
    token = token->next;
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

Node* expr();

Node* num() {
    Token* tok = parse_num();
    assert(tok);
    Node* node = new_num(tok);
    return node;
}

Node* factor() {
    if (parse_reserved("(")) {
        Node* fac = expr();
        parse_reserved(")");
        return fac;
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
    return factor();
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


Node* expr() {
    return logor();
}

Node* stmt() {
    Node* node = NULL;
    if (parse_reserved("return")) {
        Node* exp = expr();
        node = new_stmt(ND_RETURN, exp);
        assert(parse_reserved(";"));
        return node;
    }
    Node* exp = expr();
    assert(parse_reserved(";"));
    return exp;
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

Function *parse_function() {
    Type *ty = parse_basetype();
    assert(ty);
    char *name = parse_ident();
    assert(name);
    // Construct a function object
    Function *fn = new Function();
    fn->name = name;
    fn->ret_type = ty;

    assert(parse_reserved("("));
    assert(parse_reserved(")"));
    assert(parse_reserved("{"));

    // Read function body
    Node head = {};
    Node *cur = &head;
    while (!parse_reserved("}")) {
        cur->next = stmt();
        cur = cur->next;
    }

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
