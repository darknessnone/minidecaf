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
    TY_VOID = 0,
    TY_CHAR = 1,
    TY_SHORT = 1 << 1,
    TY_INT = 1 << 2,
    TY_LONG = 1 << 3,
    TY_STR = 1 << 4,
    TY_PTR = 1 << 5,
    TY_ARRAY = 1 << 6,
};

struct Type {
    TypeKind kind;
    int size;
    int align;

    Type* base;
    int array_len;
};

extern Type INT_TYPE;
extern Type CHAR_TYPE;
extern Type SHORT_TYPE;
extern Type LONG_TYPE;

int align_to(int n, int align);
Type *pointer_to(Type *base);
Type *array_of(Type *base, int size);
bool is_integer(Type* ty);
bool is_ptr(Type* ty);

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
    ND_REF,        // unary &
    ND_DEREF,      // unary *
    ND_NUM,        // int literal
    ND_ADD,        // binary +
    ND_SUB,        // binary -
    ND_PTR_ADD,    // ptr + num, [WARN] num + ptr is not supported
    ND_PTR_SUB,    // ptr - num
    ND_PTR_DIFF,   // ptr - ptr
    ND_MUL,        // binary *
    ND_DIV,        // binary /
    // ND_GT,      // binary >
    // ND_GTE,     // binary >=
    ND_LT,         // binary <
    ND_LTE,        // binary <=
    ND_EQ,         // binary ==
    ND_NEQ,        // binary !=
    ND_LOGAND,     // binary &&
    ND_LOGOR,      // binary ||
    ND_ASSIGN,     // binary =
    ND_VAR,        // variable, identifiers
    ND_DECL,
    ND_IF,
    ND_UNUSED_EXPR,
    ND_TERNARY,    // a ? b : c
    ND_BLOCK,
    ND_FOR,
    ND_BREAK,
    ND_CONTINUE,
    ND_FUNC_CALL,
};

struct Node;

struct Var {       // Local variable
    char *name;    // Variable name
    Type *ty;      // Type
    int offset;    // Offset from %rbp
    Node* init;    // initialization
    Var* next;
    bool is_local;
};

struct Function {
    Function *next;
    char *name;
    Type *ret_type;
    Node *node;
    int stack_size;
    Var* local;
    Var* arg;
    int narg;
};

struct Node {
    NodeKind kind;
    Node *next;
    Type *ty;      
    long val;      // Value of type
    Node* lexpr;
    Node* rexpr;
    Var* var;      // ND_VAR
    // 'if' statement
    Node* cond;
    Node* then;
    Node* els;
    // block statement
    Node* body;
    // 'for' statement 
    Node* init;
    Node* inc;
    // function call
    Function* func;
    Node* args;
};

struct Program {
    Function* functions;
    Var* globals;
};

Program* parsing();

// asmgen.h

void codegen();

extern char user_input[];
extern Token* token;
extern Program* prog;
extern bool debug;



