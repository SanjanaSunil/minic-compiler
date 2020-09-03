grammar Expr;

prog: (expr ';') + EOF
    ;

expr: ('+' | '-') expr
    | '!' expr
    | expr ('/' | '*' | '%') expr
    | expr ('+' | '-') expr
    | expr ('<' | '<=' | '>' | '>=') expr
    | expr ('==' | '!=') expr
    | expr '&&' expr
    | expr '||' expr
    | '(' expr ')' '?' expr ':' expr
    | ID
    | INT
    | '(' expr ')'
    ;
        

/*Tokens*/

INT : ([1-9][0-9]* | [0]) ;
ID  : [a-z][a-zA-Z0-9_]*;

COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 