#include "chibi.h"

static Token *gen_token(TokenKind kind, Token *cur, char *str, int len) {
    Token *tok = new Token();
    tok->kind = kind;
    tok->str = str;
    tok->len = len;
    tok->ty = NULL;
    tok->next = NULL;
    cur->next = tok;
    return tok;
}

bool startswith(char *p, char *q) {
    return strncmp(p, q, strlen(q)) == 0;
}

bool is_alpha(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_';
}

bool is_alnum(char c) {
    return is_alpha(c) || ('0' <= c && c <= '9');
}

char* comsume_reserved(char *p) {
    // Keyword
    static char *kw[] = {"return"};

    for (int i = 0; i < sizeof(kw) / sizeof(*kw); i++) {
        int len = strlen(kw[i]);
        if (startswith(p, kw[i]) && !is_alnum(p[len]))
        return kw[i];
    }

    return NULL;
}

static Token *read_int_literal(Token *cur, char *start) {
    char *p = start;

    // decide base
    int base = 10;

    long val = strtol(p, &p, base);
    Type *ty = &INT_TYPE;

    Token *tok = gen_token(TK_NUM, cur, start, p - start);
    tok->ty = ty;
    tok->val = val;
    return tok;
}

// Tokenize `user_input` and returns new tokens.
Token *lexing() {
    char* p = user_input;
    Token head = {};
    Token *cur = &head;

    while (*p) {
        // Skip whitespace characters.
        if (isspace(*p)) {
            p++;
            continue;
        }

        // Keywords or multi-letter punctuators
        char *kw = comsume_reserved(p);
        if (kw) {
            int len = strlen(kw);
            cur = gen_token(TK_RESERVED, cur, p, len);
            p += len;
            continue;
        }

        // Single-letter punctuators
        if (ispunct(*p)) {
            cur = gen_token(TK_RESERVED, cur, p++, 1);
            continue;
        }
    
        // Identifier
        if (is_alpha(*p)) {
            char *start = p++;
            while (is_alnum(*p))
                p++;
            cur = gen_token(TK_IDENT, cur, start, p - start);
            continue;
        }

        // Integer literal
        if (isdigit(*p)) {
            cur = read_int_literal(cur, p);
            p += cur->len;
            continue;
        }

        cout << p << "invalid token" << endl;
    }

    gen_token(TK_EOF, cur, p, 0);
    return head.next;
}