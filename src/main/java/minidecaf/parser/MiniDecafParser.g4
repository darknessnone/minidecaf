parser grammar MiniDecafParser;

options { tokenVocab = MiniDecafLexer; }

program       : NUM;

// toplv      : typ IDENT (LPAREN (typ IDENT (COMMA typ IDENT)*)? RPAREN LBRACK stmt* RBRACK | (LBRACE NUM RBRACE)* SEMI);

// stmt       : expr SEMI                                              #exprStmt
//            | LBRACE stmt* RBRACE                                    #block
//            | IF LBRACE expr RBRACE stmt (ELSE stmt)?                #ifStmt
//            | WHILE LBRACE expr RPAREN stmt                          #whileStmt
//            | FOR LBRACE expr? SEMI expr? SEMI expr? RPAREN stmt     #forStmt
//            | RETURN expr SEMI                                       #returnStmt
//            | typ IDENT (LBRACK NUM RBRACK)* SEMI                    #declStmt
//            ;

// expr       : assign;

// assign     : equality (ASSIGN assign)?;

// equality   : relational (EQUAL relational | NOTEQUAL relational)*;

// relational : add (LT add | LE add | GT add | GE add)*;

// add        : mul (ADD mul | SUB mul)*;

// mul        : unary (MUL unary | DIV unary)*;

// unary      : ADD? primary
//            | SUB? primary
//            | AND unary
//            | MUL unary
//            | SIZEOF unary
//            | primary LBRACK expr RBRACK;

// primary    : NUM
        //    | IDENT (LPAREN (expr (COMMA expr)*)? RPAREN)?
        //    | LPAREN expr RPAREN;

// typ        : (INT | CHAR) MUL*;