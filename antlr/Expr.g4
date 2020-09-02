grammar Expr;

prog: (expr ';') + EOF
    ;


expr: expr '+' expr
    | expr '-' expr
    | ID
    
    ;

/*Tokens*/

ID  : [a-z][a-zA-Z0-9_]*;
COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 