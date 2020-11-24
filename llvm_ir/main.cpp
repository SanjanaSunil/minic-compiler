#include <iostream>

#include "antlr4-runtime.h"
#include "ExprLexer.cpp"
#include "ExprParser.cpp"

#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include "utilities.h"
#include "ExprBuildASTVisitor.h"

#include "SemanticVisitor.h"

#include "IRTable.h"
#include "IRVisitor.h"
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
    
    SemanticVisitor *sv = new SemanticVisitor();
    sv->visit(*program_root);

    IRVisitor *iv = new IRVisitor();
    iv->visit(*program_root);
    iv->Module->print(llvm::errs(), nullptr);
    
    return 0;
}
