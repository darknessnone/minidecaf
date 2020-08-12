grammar MiniDecaf;

toplv : (prog)* EOF
     ;

prog : type ID ('(' (type ID ',')* (type ID)? ')' stmts | ('[' INTEGER ']')* ';' | '=' INTEGER ';') 
     ;

stmts : 'return' expr ';'                                        # Return
     | IF '(' expr ')' stmts (ELSE stmts)?                       # IfStmt
     | WHILE '(' expr ')' stmts                                  # WhileLoop
     | FOR '(' (expr)? ';' (expr)? ';' (expr)? ')' stmts         # ForLoop
     | DO stmts WHILE expr                                       # Dowhile
     | expr ';'                                                  # PrintExpr
     | '{' (stmts)* '}'                                          # StmtBlock
     | ';'                                                       # Nop
     ;

expr : ('+'|'-'|'*'|'&'|'!'|'~') expr                            # Unary
     | expr op=(MUL|DIV|MOD) expr                                # MulDiv
     | expr op=(ADD|SUB) expr                                    # AddSub
     | expr op=(LT|LE|GT|GE) expr                                # LessGreat 
     | expr op=(EQ|NEQ) expr                                     # Equal
     | expr op=LAND expr                                         # LAND
     | expr op=LOR expr                                          # LOR
     | expr QUES expr COLON expr                                 # Ternary
     | (type)? ID ('=' expr)?                                    # VarDef
     | type ID '[' INTEGER ']'                                   # ArrayDef
     | ID '(' (expr ',')* (expr)? ')'                            # CallFunc
     | SIZEOF '(' ID ')'                                         # SizeOf
     | ID '[' expr ']'                                           # ArrayCall
     | INTEGER                                                   # Literal
     | '(' expr ')'                                              # Paren
     | BREAK                                                     # Break
     | CONTINUE                                                  # Continue
     ;

type : INT ('*')*
     ;

WS : [ \t\r\n] -> skip; 
INTEGER : [0-9]+;
SEMICOLON : ';';
COMMA : ',';
ADD : '+';
SUB : '-';
MUL : '*';
AND : '&';
DIV : '/';
NOT : '!';
MOD : '%';
QUES : '?';
COLON : ':';
BITNOT : '~';
LPAREN : '(';
RPAREN : ')';
LBRACE : '{';
RBRACE : '}';
LSQUBRACE : '[';
RSQUBRACE : ']';
EQ : '==';
NEQ : '!=';
LT : '<';
LE : '<=';
GT : '>';
GE : '>=';
LAND : '&&';
LOR : '||';
ASSIGN : '=';
SIZEOF : 'sizeof';
INT : 'int';
RET : 'return';
IF : 'if';
ELSE : 'else';
WHILE : 'while';
FOR : 'for';
CONTINUE : 'continue';
BREAK : 'break';
DO : 'do';
ID : [a-zA-Z_][a-zA-Z_0-9]*;
