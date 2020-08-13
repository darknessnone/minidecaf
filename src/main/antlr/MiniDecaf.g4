grammar MiniDecaf;

program: (func | global)*;

func: 'int' IDENT '(' ('int' IDENT (',' 'int' IDENT)*)?  ')' '{' blockItem* '}' #completeFunc
    | 'int' IDENT '(' ('int' IDENT? (',' 'int' IDENT?)*)? ')' ';' #declaredFunc
    ;

global: 'int' IDENT ('=' NUM)? ';';

blockItem: local | stmt;

local: 'int' IDENT ('=' expr)? ';';

stmt: expr ';' #exprStmt
    | 'return' expr ';' #returnStmt
    | '{' blockItem* '}' #blockStmt
    | 'if' '(' expr ')' stmt ('else' stmt)? #ifStmt
    | 'while' '(' expr ')' stmt #whileStmt
    | 'for' '(' (local | expr? ';') expr? ';' expr? ')' stmt #forStmt
    | 'do' stmt 'while' '(' expr ')' ';' #doStmt
    | 'break' ';' #breakStmt
    | 'continue' ';' #continueStmt
    | ';' #emptyStmt
    ;

// TODO: right associativity of ternary conditional expression
expr: IDENT '=' expr | ternary;

ternary: or '?' expr ':' ternary | or;

or: or '||' or | and;

and: and '&&' and | eq;

eq: eq ('==' | '!=') eq | rel;

rel: rel ('<' | '<=' | '>' | '>=') rel | add;

add: add ('+' | '-') add | term;

term: term ('*' | '/' | '%') term | unary;

unary: ('!' | '~' | '-') unary | primary;

primary: NUM #numPrimary
	| IDENT #identPrimary
	| '(' expr ')' #parenthesizePrimary
        | IDENT '(' (expr (',' expr)*)? ')' #callPrimary
        ;

/* lexer */ 

WS: [ \t\r\n\u000C] -> skip;

// comment
COMMENT: '/*' .*? '*/' -> skip;
LINE_COMMENT: '//' ~[\r\n]* -> skip;

IDENT: [a-zA-Z_] [a-zA-Z_0-9]*;
NUM: [0-9]+;