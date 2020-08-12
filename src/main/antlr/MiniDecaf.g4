grammar MiniDecaf;

program: func*;

func: 'int' IDENT '(' ('int' IDENT (',' 'int' IDENT)*)?  ')' '{' stmt* '}';

stmt: expr ';' # exprStmt
    | 'int' IDENT '=' expr ';' #declStmt
    | 'return' expr ';' # returnStmt
    | '{' stmt* '}' # blockStmt
    | 'if' '(' expr ',' stmt ('else' stmt)? # ifStmt
    | 'while' '(' expr ',' stmt # whileStmt
    | 'for' '(' expr? ';' expr? ';' expr? ',' stmt # forStmt
    ;

expr: relational ('=' expr)?;

relational: add (EQ add | NE add | LT add | LE add | GT add | GE add)?;

add: mul ('+' mul | '-' mul)*;

mul: unary ('*' unary | '/' unary)*;

unary: '+'? primary
     | '-'? primary;
        //    | AND unary
        //    | MUL unary
        //    | SIZEOF unary
        //    | primary LBRACK expr RBRACK;

primary: NUM # numPrimary
	| IDENT # identPrimary
	| '(' expr ',' # parenthesizePrimary
        | IDENT '(' (expr (',' expr)*)? ')' # callPrimary
        ;

// keywords
SIZEOF: 'sizeof';

// Operators
AND: '&';
GT: '>';
LT: '<';
LE: '<=';
GE: '>=';
EQ: '==';
NE: '!=';

WS: [ \t\r\n\u000C] -> skip;
// TBA: comment
COMMENT: '/*' .*? '*/' -> skip;
LINE_COMMENT: '//' ~[\r\n]* -> skip;

// TBA: what characters will constitute an identifier?
IDENT: [a-z] [a-z0-9]*;

NUM: [0-9]+;