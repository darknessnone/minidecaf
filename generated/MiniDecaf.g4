grammar MiniDecaf;

prog : stmts EOF
     ;

stmts : expr ';'              # printExpr
     ;

expr : expr op=(ADD|SUB) expr # AddSub
     | INT                    # literal
     ;

WS : [ \t\r\n] -> skip; 
INT : [0-9]+;
SEMICOLON : ';';
ADD : '+';
SUB : '-';
