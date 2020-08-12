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
    TY_CHAR,
    TY_SHORT,
    TY_INT,
    TY_LONG,
};

struct Type {
    TypeKind kind;
    int size;
    int align;
};

extern Type INT_TYPE;
extern Type CHAR_TYPE;
extern Type SHORT_TYPE;
extern Type LONG_TYPE;

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



