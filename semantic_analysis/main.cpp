#include <iostream>

#include "antlr4-runtime.h"
#include "ExprLexer.cpp"
#include "ExprParser.cpp"

#include "ExprBuildASTVisitor.h"

// #include "PostfixVisitor.h"
//#include "ast.h"

using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;

    cout << "Processing input file " << argv[1] << endl;
    stream.open(argv[1]);
    
    ANTLRInputStream input(stream);

    ExprLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    ExprParser parser(&tokens);    

    ExprParser::ProgContext *ctx = parser.prog();

    ExprVisitor *visitor = new ExprBuildASTVisitor();

    ASTProg *program_root = visitor->visitProg(ctx);
    
    // PostFixVisitor *pv = new PostFixVisitor();
    // pv->visit(*program_root);

    return 0;
}
