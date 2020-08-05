grammar MiniDecaf;

prog : stmts EOF
     ;

stmts : expr ';'                             # printExpr
     ;

expr : ('+'|'-') expr                        # Unary 
     | expr op=(MUL|DIV) expr                # MulDiv
     | expr op=(ADD|SUB) expr                # AddSub
     | expr op=(LT|LE|GT|GE) expr            # LessGreat 
     | expr op=(EQ|NEQ) expr                 # Equal
     | INT                                   # Literal
     | '(' expr ')'                          # Paren
     ;

WS : [ \t\r\n] -> skip; 
INT : [0-9]+;
SEMICOLON : ';';
ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';
LPAREN : '(';
RPAREN : ')';
EQ : '==';
NEQ : '!=';
LT : '<';
LE : '<=';
GT : '>';
GE : '>=';
