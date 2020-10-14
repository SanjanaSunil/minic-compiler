grammar Expr;

varDecl: TYPE (variable | varAssign) ((',' variable) | (',' varAssign))* ';'    #variableDecl
        ;

/*Tokens*/

TYPE : ('uint' | 'int' | 'long' | 'float' | 'bool' | 'char' | 'string') ;

INT : ([1-9][0-9]* | [0]) ;
FLOAT : ([0-9]+ '.' [0-9]+) ;
BOOL : ('true' | 'false') ;
CHAR : ('\'' . '\'' | '\'' '\\' [ntr] '\'') ;
STRING : '"' .*? '"' ;
ID : [a-zA-Z_][a-zA-Z0-9_]* ;

COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 