#include <iostream>
#include <unordered_set>

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

void printEBB(unordered_set<llvm::BasicBlock*>& used_blocks, llvm::BasicBlock* B, string spaces) {
    used_blocks.insert(B);

    llvm::errs() << spaces << B->getName() << "\n";
    for(auto *S : llvm::successors(B))
    {
        if(!(S->hasNPredecessorsOrMore(2)))
            printEBB(used_blocks, S, spaces + "  ");
    }
}


int main(int argc, const char* argv[]) {
    std::ifstream stream;

    // cout << "Processing input file " << argv[1] << endl;
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
    // iv->Module->print(llvm::errs(), nullptr);
    
    error_code err;
    string file = "tmp.bc";
    auto fd = new llvm::raw_fd_ostream(
            llvm::StringRef(file), 
            err
        );
    iv->Module->print(*fd, nullptr);

    unordered_set<llvm::BasicBlock*> used_blocks;
    for (auto&F : *(iv->Module)) 
    {
        if(F.getName() == "printf" || F.getName() == "scanf") continue;
        
        llvm::errs() << "Function: " << F.getName() << "\n";
        llvm::errs() << "=====================\n\n";

        for(llvm::Function::iterator b = F.begin(), be = F.end(); b != be; ++b)
        {
            llvm::BasicBlock* B = llvm::dyn_cast<llvm::BasicBlock>(&*b);

            if(used_blocks.find(B) == used_blocks.end()) 
            {
                printEBB(used_blocks, B, "");
                llvm::errs() << "\n\n";
            }
        }
    }

    return 0;
}
