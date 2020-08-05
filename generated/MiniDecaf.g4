grammar MiniDecaf;

prog : stmts EOF
     ;

stmts : expr ';'        # printExpr
     ;

expr : INT              # literal
     ;

WS : [ \t\r\n] -> skip; 
INT : [0-9]+;
SEMICOLON : ';';
