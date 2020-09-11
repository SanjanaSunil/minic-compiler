grammar Expr;

prog: (expr ';') + EOF
    ;

literal: INT
       | FLOAT
       | CHAR
       | BOOL
       ;

variable: ID
        | ID '[' expr ']'
        | ID '[' expr ']' '[' expr ']'
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
    | variable
    | literal
    | '(' expr ')'
    ;
        

/*Tokens*/

INT : ([1-9][0-9]* | [0]) ;
FLOAT : ([0-9]+ '.' [0-9]+) ;
BOOL : ('true' | 'false') ;
CHAR : ('\'' . '\'' | '\'' '\\' [ntr] '\'') ;
ID : [a-zA-Z_][a-zA-Z0-9_]* ;

TYPE : ('uint' | 'int' | 'bool' | 'char' | 'long') ;

COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 
