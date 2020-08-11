parser grammar MiniDecafParser;

options { tokenVocab = MiniDecafLexer; }

program: stmt*;

// toplv      : typ IDENT (LPAREN (typ IDENT (COMMA typ IDENT)*)? RPAREN LBRACK stmt* RBRACK | (LBRACE NUM RBRACE)* SEMI);

// func: IDENT (LPAREN (IDENT (COMMA IDENT)*)?) LBRACE stmt* RBRACE;

stmt: expr SEMI # exprStmt
    | RETURN expr SEMI # returnStmt
    | LBRACE stmt* RBRACE # blockStmt
    | IF LPAREN expr RPAREN stmt (ELSE stmt)? # ifStmt
    | WHILE LPAREN expr RPAREN stmt # whileStmt
    | FOR LPAREN expr? SEMI expr? SEMI expr? RPAREN stmt # forStmt
    ;
//            | typ IDENT (LBRACK NUM RBRACK)* SEMI                    #declStmt

expr: relational (ASSIGN expr)?;

// equality   : relational (EQUAL relational | NOTEQUAL relational);

relational: add (EQ add | NE add | LT add | LE add | GT add | GE add)?;

add: mul (ADD mul | SUB mul)*;

mul: unary (MUL unary | DIV unary)*;

unary: ADD? primary
     | SUB? primary;
        //    | AND unary
        //    | MUL unary
        //    | SIZEOF unary
        //    | primary LBRACK expr RBRACK;

primary: NUM # numPrimary
	| IDENT # identPrimary
	| LPAREN expr RPAREN # parenthesizePrimary;
        //    | IDENT (LPAREN (expr (COMMA expr)*)? RPAREN)?

// typ        : (INT | CHAR) MUL*;