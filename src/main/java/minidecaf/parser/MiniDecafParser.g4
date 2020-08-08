parser grammar MiniDecafParser;

options { tokenVocab = MiniDecafLexer; }

program: stmt*;

// toplv      : typ IDENT (LPAREN (typ IDENT (COMMA typ IDENT)*)? RPAREN LBRACK stmt* RBRACK | (LBRACE NUM RBRACE)* SEMI);

stmt: expr SEMI;
//            | LBRACE stmt* RBRACE                                    #block
//            | IF LBRACE expr RBRACE stmt (ELSE stmt)?                #ifStmt
//            | WHILE LBRACE expr RPAREN stmt                          #whileStmt
//            | FOR LBRACE expr? SEMI expr? SEMI expr? RPAREN stmt     #forStmt
//            | RETURN expr SEMI                                       #returnStmt
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