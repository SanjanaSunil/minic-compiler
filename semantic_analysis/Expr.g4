grammar Expr;

prog: expr + EOF
    ;

expr: op=('+' | '-') expr                       #exprUnary
    | op='!' expr                                  #exprNot
    | expr op=('/' | '*' | '%') expr            #exprDivMulMod
    | expr op=('+' | '-') expr                  #exprAddSub
    | expr op=('<' | '<=' | '>' | '>=') expr    #exprComp
    | expr op=('==' | '!=') expr                #exprEq
    | expr op='&&' expr                         #exprAnd
    | expr op='||' expr                         #exprOr
    | INT                                       #exprInt
    | FLOAT                                     #exprFloat
    | CHAR                                      #exprChar
    | BOOL                                      #exprBool
    | STRING                                    #exprString
    | '(' expr ')'                              #exprParenthesis
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