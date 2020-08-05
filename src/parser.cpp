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

bool parse_int_literal(int* val) {
    Token* tok;
    if(!(tok = expect_int_literal()))
        return false;
    *val = tok->val;
    return true;
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
    char* s = token->str;
    token = token->next;
    return s;
}

Node* parse_node_stmt() {
    Node* node = NULL;
    if (parse_reserved("return")) {
        int val;
        assert(parse_int_literal(&val));
        node = new_node(ND_RETURN);
        node->val = val;
        assert(parse_reserved(";"));
        return node;
    }
    return node;
}

// <program> ::= <function>
// <function> ::= <type> <id> "(" ")" "{" <statement> "}"
// <type> ::= "int"
// <statement> ::= "return" <exp> ";"
// <exp> ::= <int>

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
        cur->next = parse_node_stmt();
        cur = cur->next;
    }

    fn->node = head.next;
    return fn;
}

Function* parsing() {
    Function head = {};
    Function *cur = &head;

    while (!token->kind == TK_EOF) {
        Function *fn = parse_function();
        if (!fn)
            continue;
        cur->next = fn;
        cur = cur->next;
        continue;
    }
    return head.next;
}
