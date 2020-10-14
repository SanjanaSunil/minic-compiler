grammar Expr;

prog: (varDecl | functionDecl)* 'func int main()' block + EOF
    ;

functionDecl: 'func' (TYPE | 'void') ID '(' (functionArgument)? (',' functionArgument)* ')' block       #funcDecl
            ;

functionCall: ID '(' (expr)? (',' expr)* ')'        #funcCall
            ;

expr:  functionCall                         #exprFuncCall
    ;
        
statement: functionCall ';'                 #statFuncCall
         | 'return' (expr)? ';'             #statReturn
         | 'break' ';'                      #statBreak
         | 'continue' ';'                   #statContinue
         | 'while' '(' expr ')' block       #statWhile
         | 'if' '(' expr ')' block ('elif' '(' expr ')' block)* ('else' block)?     #statIf
         | 'for' '(' ((TYPE)? variable '=' expr)? ';' (expr)? ';' (variable '=' expr)? ')' block    #statFor
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