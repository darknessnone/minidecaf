#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;

// lexer.h

enum TokenKind {
  TK_RESERVED, // Keywords or punctuators
  TK_IDENT,    // Identifiers
  TK_NUM,      // Integer literals
  TK_EOF,      // End-of-file markers
};

enum TypeKind {
    TY_INT,
};

struct Type {
    TypeKind kind;
};

extern Type INT_TYPE;

// Token type
struct Token {
    TokenKind kind; // Token kind
    Token *next;    // Next token
    Type *ty;       // Used if TK_NUM
    long val;       // Value of type
    char *str;      // Token string
    int len;        // Token length
};

void show_token(Token* tok);
Token* lexing();


// parser.h

enum NodeKind{
    ND_RETURN,     // "return"
    ND_NOT,        // unary !
    ND_BITNOT,     // unary ~
    ND_NEG,        // unary -
    ND_NUM,        // int literal
    ND_ADD,        // binary +
    ND_SUB,        // binary -
    ND_MUL,        // binary *
    ND_DIV,        // binary /
};

struct Node {
    NodeKind kind; // Node kind
    Node *next;    // Next node
    Type *ty;      // Type, e.g. int or pointer to int
    Node* lexpr;
    Node* rexpr;
    long val;      // Value of type
};

struct Function {
  Function *next;
  char *name;
  Type *ret_type;
  Node *node;
  int stack_size;
};

Function* parsing();

// asmgen.h

void codegen();

extern char user_input[];
extern Token* token;
extern Function* func;