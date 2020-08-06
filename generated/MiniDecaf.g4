grammar MiniDecaf;

prog : (stmts)* EOF
     ;

stmts : 'return' expr ';'                    # Return
     | ID '=' expr ';'                       # Assign
     | expr ';'                              # PrintExpr
     ;

expr : ('+'|'-') expr                        # Unary 
     | expr op=(MUL|DIV) expr                # MulDiv
     | expr op=(ADD|SUB) expr                # AddSub
     | expr op=(LT|LE|GT|GE) expr            # LessGreat 
     | expr op=(EQ|NEQ) expr                 # Equal
     | ID                                    # Identifier
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
ASSIGN : '=';
RET : 'return';
ID : [a-zA-Z_][a-zA-Z_0-9]*;
