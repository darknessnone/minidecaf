grammar MiniDecaf;

prog : (stmts)* EOF
     ;

stmts : 'return' expr ';'                                        # Return
     | IF '(' expr ')' stmts (ELSE stmts)?                       # IfStmt
     | WHILE '(' expr ')' stmts                                  # WhileLoop
     | FOR '(' (expr)? ';' (expr)? ';' (expr)? ')' stmts         # ForLoop
     | type ID '(' (type ID ',')* (type ID)? ')' stmts           # FuncDef
     | expr ';'                                                  # PrintExpr
     | '{' (stmts)* '}'                                          # StmtBlock
     ;

expr : ('+'|'-'|'*'|'&') expr                                    # Unary
     | expr op=(MUL|DIV) expr                                    # MulDiv
     | expr op=(ADD|SUB) expr                                    # AddSub
     | expr op=(LT|LE|GT|GE) expr                                # LessGreat 
     | expr op=(EQ|NEQ) expr                                     # Equal
     | type ID '=' expr                                          # Assign
     | ID '(' (expr ',')* (expr)? ')'                            # CallFunc
     | ID                                                        # Identifier
     | INTEGER                                                   # Literal
     | '(' expr ')'                                              # Paren
     ;

type : INT
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
INT : 'int';
RET : 'return';
IF : 'if';
ELSE : 'else';
WHILE : 'while';
FOR : 'for';
ID : [a-zA-Z_][a-zA-Z_0-9]*;
