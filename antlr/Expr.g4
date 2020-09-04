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
    | FLOAT
    | '(' expr ')'
    ;
        

/*Tokens*/

INT : ([1-9][0-9]* | [0]) ;
FLOAT : ([0-9]+ '.'? [0-9]+) ;
ID  : [a-z][a-zA-Z0-9_]*;

COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 