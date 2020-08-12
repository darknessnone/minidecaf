lexer grammar MiniDecafLexer;

// keywords
IF: 'if';
ELSE: 'else';
WHILE: 'while';
FOR: 'for';
RETURN: 'return';
SIZEOF: 'sizeof';
INT: 'int';
CHAR: 'char';

// Operators
ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
AND: '&';
ASSIGN: '=';
GT: '>';
LT: '<';
LE: '<=';
GE: '>=';
EQ: '==';
NE: '!=';

// Separators
LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
LBRACK: '[';
RBRACK: ']';
SEMI: ';';
COMMA: ',';

WS: [ \t\r\n\u000C] -> skip;
// TBA: comment
COMMENT: '/*' .*? '*/' -> skip;
LINE_COMMENT: '//' ~[\r\n]* -> skip;

// TBA: what characters will constitute an identifier?
IDENT: [a-z] [a-z0-9]*;

NUM: [0-9]+;