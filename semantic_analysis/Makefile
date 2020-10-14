ANTLR4=java -Xmx500M -cp "/usr/local/lib/antlr-4.8-complete.jar:$CLASSPATH" org.antlr.v4.Tool

antlr:	Expr.g4
		$(ANTLR4) -Dlanguage=Cpp -no-listener -visitor Expr.g4
		g++ -g main.cpp -o expr -I/usr/local/include/antlr4-runtime -lantlr4-runtime

clean:	
		rm -f ExprLexer.h ExprParser.h expr *.tokens *.interp ExprBaseVisitor.cpp \
		rm -f ExprBaseVisitor.h ExprParser.cpp ExprLexer.cpp ExprBaseVisitor.cpp  \ 
		rm -f ExprVisitor.cpp  ExprVisitor.h

