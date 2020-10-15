#include <iostream>
#include "ast.h"
#include <vector>
#include "ExprVisitor.h"

using namespace std;

class ExprBuildASTVisitor : public ExprVisitor
{
public:
    /**
   * Visit parse trees produced by ExprParser.
   */
    virtual antlrcpp::Any visitProg(ExprParser::ProgContext *context)
    {
        cout << "In visitProg" << endl;
        ASTProg *node = new ASTProg();

        ASTProgStat *progStatNode;
        for (auto progStat : context->progStatement())
        {
            progStatNode = visit(progStat);
            if (progStatNode != nullptr)
            {
                node->progStatList.push_back(progStatNode);
            }
        }

        node->node_type = NONE;
        return (ASTProg *) node;
    }

    virtual antlrcpp::Any visitProgStat(ExprParser::ProgStatContext *context)
    {
        cout << "In visitProgStat" << endl;

        ASTVariableDecl *var_decl = (ASTVariableDecl *) nullptr;
        ASTFuncDecl *func_decl = (ASTFuncDecl *) nullptr;

        if(context->varDecl()) var_decl = visit(context->varDecl());
        if(context->functionDecl()) func_decl = visit(context->functionDecl());

        ASTProgStat *node = new ASTProgStat(var_decl, func_decl);
        node->node_type = NONE;
        return (ASTProgStat *) node;
    }

    virtual antlrcpp::Any visitBlockStat(ExprParser::BlockStatContext *context)
    {
        cout << "In visitBlockStat" << endl;
        ASTBlockStat *node = new ASTBlockStat();
        ASTStat *statementNode;

        for (auto statement : context->statement())
        {
            statementNode = visit(statement);
            if (statementNode != nullptr)
            {
                node->statementList.push_back(statementNode);
            }
        }

        node->node_type = NONE;
        return (ASTBlockStat *) node;
    }

    virtual antlrcpp::Any visitVarId(ExprParser::VarIdContext *context)
    {
        cout << "In visitVarId" << endl;
        string id = context->ID()->getText();
        
        ASTVariable *node = new ASTVariable(id, (ASTExpr *) nullptr, (ASTExpr *) nullptr);
        node->node_type = NONE;
        return (ASTVariable *) node;
    }

    virtual antlrcpp::Any visitVarArrOneD(ExprParser::VarArrOneDContext *context)
    {
        cout << "In visitVarArrOneD" << endl;
        string id = context->ID()->getText();
        ASTExpr* param = visit(context->expr());

        ASTVariable *node = new ASTVariable(id, param, (ASTExpr *) nullptr);
        node->node_type = NONE;
        return (ASTVariable *) node;
    }

    virtual antlrcpp::Any visitVarArrTwoD(ExprParser::VarArrTwoDContext *context)
    {
        cout << "In visitVarArrTwoD" << endl;
        string id = context->ID()->getText();
        ASTExpr* param1 = visit(context->expr(0));
        ASTExpr* param2 = visit(context->expr(1));

        ASTVariable *node = new ASTVariable(id, param1, param2);
        node->node_type = NONE;
        return (ASTVariable *) node;
    }

    virtual antlrcpp::Any visitVariableAssign(ExprParser::VariableAssignContext *context)
    {
        cout << "In visitVariableAssign" << endl;
        string id = context->ID()->getText();
        ASTExpr* exp = visit(context->expr());

        ASTVariableAssign *node = new ASTVariableAssign(id, exp);
        node->node_type = exp->node_type;
        return (ASTVariableAssign *) node;
    }

    virtual antlrcpp::Any visitVariableDecl(ExprParser::VariableDeclContext *context)
    {
        cout << "In visitVariableDecl" << endl;
        string lit_type = context->TYPE()->getText();
        ASTVariableDecl *node = new ASTVariableDecl(lit_type);

        ASTVariableDeclType *variableNode = visit(context->varDeclTypeA());
        if (variableNode != nullptr) node->varList.push_back(variableNode);

        for (auto variable : context->varDeclTypeB())
        {
            variableNode = visit(variable);
            if (variableNode != nullptr)
            {
                node->varList.push_back(variableNode);
            }
        }

        node->node_type = getNodeType(lit_type);
        return (ASTVariableDecl *) node;
    }

    virtual antlrcpp::Any visitVariableDeclTypeA(ExprParser::VariableDeclTypeAContext *context)
    {
        cout << "In visitVariableDeclA" << endl;
        ASTVariable* var = (ASTVariable *) nullptr;
        ASTVariableAssign* var_assign = (ASTVariableAssign *) nullptr;

        if(context->variable()) var = visit(context->variable());
        if(context->varAssign()) var_assign = visit(context->varAssign());

        ASTVariableDeclType *node = new ASTVariableDeclType(var, var_assign);

        node->node_type = NONE;
        if(context->varAssign()) node->node_type = var_assign->node_type;

        return (ASTVariableDeclType *) node;
    }

    virtual antlrcpp::Any visitVariableDeclTypeB(ExprParser::VariableDeclTypeBContext *context)
    {
        cout << "In visitVariableDeclB" << endl;
        ASTVariable* var = (ASTVariable *) nullptr;
        ASTVariableAssign* var_assign = (ASTVariableAssign *) nullptr;

        if(context->variable()) var = visit(context->variable());
        if(context->varAssign()) var_assign =visit(context->varAssign());

        ASTVariableDeclType *node = new ASTVariableDeclType(var, var_assign);

        node->node_type = NONE;
        if(context->varAssign()) node->node_type = var_assign->node_type;
        
        return (ASTVariableDeclType *) node;
    }

    virtual antlrcpp::Any visitFuncArg(ExprParser::FuncArgContext *context)
    {
        cout << "In visitFuncArg" << endl;
        string lit_type = context->TYPE()->getText();
        string id = context->ID()->getText();

        ASTFuncArg *node = new ASTFuncArg(lit_type, id, 0);
        
        node->node_type = getNodeType(lit_type);
        return (ASTFuncArg *) node;
    }

    virtual antlrcpp::Any visitFuncArgArrOneD(ExprParser::FuncArgArrOneDContext *context)
    {
        cout << "In visitFuncArgArrOneD" << endl;
        string lit_type = context->TYPE()->getText();
        string id = context->ID()->getText();

        ASTFuncArg *node = new ASTFuncArg(lit_type, id, 1);
        node->node_type = getNodeType(lit_type);
        return (ASTFuncArg *) node;
    }

    virtual antlrcpp::Any visitFuncArgArrTwoD(ExprParser::FuncArgArrTwoDContext *context)
    {
        cout << "In visitFuncArgArrTwoD" << endl;
        string lit_type = context->TYPE()->getText();
        string id = context->ID()->getText();

        ASTFuncArg *node = new ASTFuncArg(lit_type, id, 2);
        
        node->node_type = getNodeType(lit_type);
        return (ASTFuncArg *) node;
    }

    virtual antlrcpp::Any visitFuncDecl(ExprParser::FuncDeclContext *context)
    {
        cout << "In visitFuncDecl" << endl;
        string lit_type = context->functype->getText();
        string id = context->ID()->getText();
        ASTBlockStat *block = visit(context->block());

        ASTFuncDecl *node = new ASTFuncDecl(lit_type, id, block);
        ASTFuncArg *funcArgNode;
        for (auto funcArg : context->functionArgument())
        {
            funcArgNode = visit(funcArg);
            if (funcArgNode != nullptr)
            {
                node->funcArgList.push_back(funcArgNode);
            }
        }

        node->node_type = getNodeType(lit_type);
        return (ASTFuncDecl *) node;
    }

    virtual antlrcpp::Any visitFuncCall(ExprParser::FuncCallContext *context)
    {
        cout << "In visitFuncCall" << endl;
        string id = context->ID()->getText();
        ASTFuncCall *node = new ASTFuncCall(id);

        ASTExpr *funcArgNode;
        for (auto funcArg : context->expr())
        {
            funcArgNode = visit(funcArg);
            if (funcArgNode != nullptr)
            {
                node->funcArgList.push_back(funcArgNode);
            }
        }

        node->node_type = NONE;
        return (ASTFuncCall *) node;
    }

    virtual antlrcpp::Any visitExprVar(ExprParser::ExprVarContext *context)
    {
        cout << "In visitExprVar" << endl;
        ASTVariable *var = visit(context->variable());
        ASTExprVar *node = new ASTExprVar(var);
        node->node_type = NONE;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprUnary(ExprParser::ExprUnaryContext *context)
    {
        cout << "In visitExprUnary" << endl;
        string op = context->op->getText();
        ASTExpr *exp = visit(context->expr());

        ASTExprUnary *node = new ASTExprUnary(op, exp);
        node->node_type = INT;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprNot(ExprParser::ExprNotContext *context)
    {
        cout << "In visitExprNot" << endl;
        string op = context->op->getText();
        ASTExpr *exp = visit(context->expr());

        ASTExprUnary *node = new ASTExprUnary(op, exp);
        node->node_type = BOOL;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprDivMulMod(ExprParser::ExprDivMulModContext *context)
    {
        cout << "In visitExprDivMulMod" << endl;

        string op = context->op->getText();
        ASTExpr *left = visit(context->expr(0));
        ASTExpr *right = visit(context->expr(1));

        ASTExprBinary *node = new ASTExprBinary(op, left, right);
        node->node_type = INT;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprAddSub(ExprParser::ExprAddSubContext *context)
    {
        cout << "In visitExprAddSub" << endl;

        string op = context->op->getText();
        ASTExpr *left = visit(context->expr(0));
        ASTExpr *right = visit(context->expr(1));

        ASTExprBinary *node = new ASTExprBinary(op, left, right);
        node->node_type = INT;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprComp(ExprParser::ExprCompContext *context)
    {
        cout << "In visitExprComp" << endl;

        string op = context->op->getText();
        ASTExpr *left = visit(context->expr(0));
        ASTExpr *right = visit(context->expr(1));

        ASTExprBinary *node = new ASTExprBinary(op, left, right);
        node->node_type = BOOL;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprEq(ExprParser::ExprEqContext *context)
    {
        cout << "In visitExprEq" << endl;

        string op = context->op->getText();
        ASTExpr *left = visit(context->expr(0));
        ASTExpr *right = visit(context->expr(1));

        ASTExprBinary *node = new ASTExprBinary(op, left, right);
        node->node_type = BOOL;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprAnd(ExprParser::ExprAndContext *context)
    {
        cout << "In visitExprAnd" << endl;

        string op = context->op->getText();
        ASTExpr *left = visit(context->expr(0));
        ASTExpr *right = visit(context->expr(1));

        ASTExprBinary *node = new ASTExprBinary(op, left, right);
        node->node_type = BOOL;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprOr(ExprParser::ExprOrContext *context)
    {
        cout << "In visitExprOr" << endl;

        string op = context->op->getText();
        ASTExpr *left = visit(context->expr(0));
        ASTExpr *right = visit(context->expr(1));

        ASTExprBinary *node = new ASTExprBinary(op, left, right);
        node->node_type = BOOL;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprTernary(ExprParser::ExprTernaryContext *context)
    {
        cout << "In visitExprTernary" << endl;

        ASTExpr *first_node = visit(context->expr(0));
        ASTExpr *second_node = visit(context->expr(1));
        ASTExpr *third_node = visit(context->expr(2));

        ASTExprTernary *node = new ASTExprTernary(first_node, second_node, third_node);
        node->node_type = second_node->node_type;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprInt(ExprParser::ExprIntContext *context)
    {
        cout << "In visitExprInt" << endl;
        ASTExprInt *node = new ASTExprInt(stoi(context->INT()->getText()));
        node->node_type = INT;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprFloat(ExprParser::ExprFloatContext *context)
    {
        cout << "In visitExprFloat" << endl;
        ASTExprFloat *node = new ASTExprFloat(stof(context->FLOAT()->getText()));
        node->node_type = FLOAT;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprChar(ExprParser::ExprCharContext *context)
    {
        cout << "In visitExprChar" << endl;
        ASTExprChar *node = new ASTExprChar((context->CHAR()->getText())[0]);
        node->node_type = CHAR;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprBool(ExprParser::ExprBoolContext *context)
    {
        cout << "In visitExprBool" << endl;
        string bool_type = context->BOOL()->getText();

        ASTExprBool *node;
        if(bool_type == "true") node = new ASTExprBool(true);
        else node = new ASTExprBool(false);

        node->node_type = BOOL;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprString(ExprParser::ExprStringContext *context)
    {
        cout << "In visitExprString" << endl;
        ASTExprString *node = new ASTExprString(context->STRING()->getText());
        
        node->node_type = STRING;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprParenthesis(ExprParser::ExprParenthesisContext *context)
    {
        cout << "In visitExprParenthesis" << endl;
        return visit(context->expr());
    }

    virtual antlrcpp::Any visitExprFuncCall(ExprParser::ExprFuncCallContext *context)
    {
        cout << "In visitExprFuncCall" << endl;
        ASTFuncCall *func_call = visit(context->functionCall());
        ASTExprFuncCall *node = new ASTExprFuncCall(func_call);

        node->node_type = NONE;
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitStatVarAssign(ExprParser::StatVarAssignContext *context)
    {
        cout << "In visitStatVarAssign" << endl;
        ASTVariable *var = visit(context->variable());
        ASTExpr *exp = visit(context->expr());

        ASTStatVarAssign *node = new ASTStatVarAssign(var, exp);
        node->node_type = exp->node_type;
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitStatVarDecl(ExprParser::StatVarDeclContext *context)
    {
        cout << "In visitStatVarDecl" << endl;
        ASTVariableDecl *var_decl = visit(context->varDecl());
        ASTStatVarDecl *node = new ASTStatVarDecl(var_decl);
        node->node_type = var_decl->node_type;
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitStatBlock(ExprParser::StatBlockContext *context)
    {
        cout << "In visitStatBlock" << endl;
        ASTBlockStat *block = visit(context->block());
        ASTStatBlock *node = new ASTStatBlock(block);
        node->node_type = NONE;
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitStatFuncCall(ExprParser::StatFuncCallContext *context)
    {
        cout << "In visitStatFuncCall" << endl;
        ASTFuncCall *func_call = visit(context->functionCall());
        ASTStatFuncCall *node = new ASTStatFuncCall(func_call);
        node->node_type = NONE;
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitStatReturn(ExprParser::StatReturnContext *context)
    {
        cout << "In visitStatReturn" << endl;
        ASTExpr *exp = (ASTExpr *) nullptr;
        if(context->expr()) exp = visit(context->expr());

        ASTStatReturn *node = new ASTStatReturn(exp);
        if(context->expr()) node->node_type = exp->node_type;
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitStatBreak(ExprParser::StatBreakContext *context)
    {
        cout << "In visitStatBreak" << endl;
        ASTStatLoopControl *node = new ASTStatLoopControl("break");
        node->node_type = NONE;
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitStatContinue(ExprParser::StatContinueContext *context)
    {
        cout << "In visitStatContinue" << endl;
        ASTStatLoopControl *node = new ASTStatLoopControl("continue");
        node->node_type = NONE;
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitStatWhile(ExprParser::StatWhileContext *context)
    {
        cout << "In visitStatWhile" << endl;
        ASTExpr *exp = visit(context->expr());
        ASTBlockStat *block = visit(context->block());
        ASTStatWhile *node = new ASTStatWhile(exp, block);

        node->node_type = NONE;
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitStatIf(ExprParser::StatIfContext *context)
    {
        cout << "In visitStatIf" << endl;
        ASTStatIf *node = new ASTStatIf();

        ASTExpr *exprNode;
        for (auto expr : context->expr())
        {
            exprNode = visit(expr);
            if (exprNode != nullptr)
            {
                node->exprList.push_back(exprNode);
            }
        }

        ASTBlockStat *blockNode;
        for (auto block : context->block())
        {
            blockNode = visit(block);
            if (blockNode != nullptr)
            {
                node->blockList.push_back(blockNode);
            }
        }

        node->node_type = NONE;
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitStatFor(ExprParser::StatForContext *context)
    {
        cout << "In visitStatFor" << endl;

        ASTVariableDecl *var_decl = (ASTVariableDecl *) nullptr;
        if(context->varDecl()) var_decl = visit(context->varDecl());

        ASTVariable *init_var = (ASTVariable *) nullptr;
        if(context->initvar) init_var = visit(context->initvar);

        ASTExpr *init_expr = (ASTExpr *) nullptr;
        if(context->initexpr) init_expr =  visit(context->initexpr);

        ASTExpr *cond_expr = (ASTExpr *) nullptr;
        if(context->condexpr) cond_expr =  visit(context->condexpr);

        ASTVariable *loop_var = (ASTVariable *) nullptr;
        if(context->loopvar) loop_var = visit(context->loopvar);

        ASTExpr *loop_expr = (ASTExpr *) nullptr;
        if(context->loopexpr) loop_expr = visit(context->loopexpr);

        ASTBlockStat *loopblock = visit(context->block());

        ASTStatFor *node = new ASTStatFor(var_decl, init_var, init_expr, cond_expr, loop_var, loop_expr, loopblock);
        node->node_type = NONE;
        return (ASTStat *) node;
    }

};