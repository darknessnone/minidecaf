grammar MiniDecaf;

prog : (stmts)* EOF
     ;

stmts : 'return' expr ';'                                        # Return
     | IF '(' expr ')' stmts (ELSE stmts)?                       # IfStmt
     | WHILE '(' expr ')' stmts                                  # WhileLoop
     | FOR '(' (expr)? ';' (expr)? ';' (expr)? ')' stmts         # ForLoop
     | ID '(' (ID ',')* (ID)? ')' stmts                          # FuncDef
     | expr ';'                                                  # PrintExpr
     | '{' (stmts)* '}'                                          # StmtBlock
     ;

expr : ('+'|'-') expr                                            # Unary 
     | expr op=(MUL|DIV) expr                                    # MulDiv
     | expr op=(ADD|SUB) expr                                    # AddSub
     | expr op=(LT|LE|GT|GE) expr                                # LessGreat 
     | expr op=(EQ|NEQ) expr                                     # Equal
     | ID '=' expr                                               # Assign
     | ID '(' (expr ',')* (expr)? ')'                             # CallFunc
     | ID                                                        # Identifier
     | INT                                                       # Literal
     | '(' expr ')'                                              # Paren
     ;

WS : [ \t\r\n] -> skip; 
INT : [0-9]+;
SEMICOLON : ';';
COMMA : ',';
ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';
LPAREN : '(';
RPAREN : ')';
LBRACE : '{';
RBRACE : '}';
EQ : '==';
NEQ : '!=';
LT : '<';
LE : '<=';
GT : '>';
GE : '>=';
ASSIGN : '=';
RET : 'return';
IF : 'if';
ELSE : 'else';
WHILE : 'while';
FOR : 'for';
ID : [a-zA-Z_][a-zA-Z_0-9]*;
