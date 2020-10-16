#include <string>
#include <vector>

using namespace std;

class ASTProg;
class ASTProgStat;

class ASTBlockStat;

class ASTVariable;
class ASTVariableAssign;
class ASTVariableDecl;
class ASTVariableDeclType;

class ASTFuncArg;
class ASTFuncDecl;
class ASTFuncCall;

class ASTExpr;
class ASTExprUnary;
class ASTExprBinary;
class ASTExprTernary;
class ASTExprInt;
class ASTExprFloat;
class ASTExprChar;
class ASTExprBool;
class ASTExprString;
class ASTExprVar;
class ASTExprFuncCall;

class ASTStat;
class ASTStatVarAssign;
class ASTStatVarDecl;
class ASTStatBlock;
class ASTStatFuncCall;
class ASTStatReturn;
class ASTStatLoopControl;
class ASTStatWhile;
class ASTStatIf;
class ASTStatFor;

class ASTvisitor
{
public:
    virtual void visit(ASTProg &node) = 0;
    virtual void visit(ASTProgStat &node) = 0;
    virtual void visit(ASTBlockStat &node) {};
    virtual void visit(ASTVariable &node) {};
    virtual void visit(ASTVariableAssign &node) {};
    virtual void visit(ASTVariableDecl &node) {};
    virtual void visit(ASTVariableDeclType &node) {};
    virtual void visit(ASTFuncArg &node) {};
    virtual void visit(ASTFuncDecl &node) {};
    virtual void visit(ASTFuncCall &node) {};

    virtual void visit(ASTExprUnary &node) {};
    virtual void visit(ASTExprBinary &node) {};
    virtual void visit(ASTExprTernary &node) {};
    virtual void visit(ASTExprInt &node) {};
    virtual void visit(ASTExprFloat &node) {};
    virtual void visit(ASTExprChar &node) {};
    virtual void visit(ASTExprBool &node) {};
    virtual void visit(ASTExprString &node) {};
    virtual void visit(ASTExprVar &node) {};
    virtual void visit(ASTExprFuncCall &node) {};
    virtual void visit(ASTExpr &node) {};

    virtual void visit(ASTStatFor &node) {};
    virtual void visit(ASTStatIf &node) {};
    virtual void visit(ASTStatWhile &node) {};
    virtual void visit(ASTStatLoopControl &node) {};
    virtual void visit(ASTStatReturn &node) {};
    virtual void visit(ASTStatFuncCall &node) {};
    virtual void visit(ASTStatVarDecl &node) {};
    virtual void visit(ASTStatVarAssign &node) {};
    virtual void visit(ASTStat &node) {};
};

class ASTnode
{
public:
    NodeType node_type;
    virtual ~ASTnode()
    {
    }

    virtual void accept(ASTvisitor &V) = 0;
};

class ASTProg : public ASTnode
{
public:
    std::vector<ASTProgStat *> progStatList;

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTProgStat : public ASTnode
{
public:
    ASTVariableDecl *var_decl;
    ASTFuncDecl *func_decl;

    ASTProgStat(ASTVariableDecl *_var_decl, ASTFuncDecl *_func_decl) : var_decl(_var_decl), func_decl(_func_decl) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTBlockStat : public ASTnode
{
public:
    std::vector<ASTStat *> statementList;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVariable : public ASTnode
{
public:
    string id;
    ASTExpr *param1;
    ASTExpr *param2;

    ASTVariable(string id, ASTExpr *_param1, ASTExpr *_param2) : id(id), param1(_param1), param2(_param2) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }

    int getDimensions() {
        if(!param1) return 0;
        if(!param2) return 1;
        return 2;
    }
};

class ASTVariableAssign : public ASTnode
{
public:
    string id;
    ASTExpr *exp;

    ASTVariableAssign(string id, ASTExpr *_exp) : id(id), exp(_exp) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVariableDecl : public ASTnode
{
public:
    string lit_type;

    vector<ASTVariableDeclType*> varList;
    ASTVariableDecl(string lit_type) : lit_type(lit_type) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVariableDeclType : public ASTnode
{
public:
    ASTVariable* var;
    ASTVariableAssign* var_assign;

    ASTVariableDeclType(ASTVariable* var, ASTVariableAssign* var_assign) : var(var), var_assign(var_assign) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }

    string getId() {
        if(var) return var->id;
        return var_assign->id;
    }
};

// Func

class ASTFuncArg : public ASTnode
{
public:
    string lit_type;
    string id;
    int dimension;

    ASTFuncArg(string lit_type, string id, int dimension) : lit_type(lit_type), id(id), dimension(dimension) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFuncDecl : public ASTnode
{
public:
    string lit_type;
    string id;
    ASTBlockStat* block;

    vector<ASTFuncArg*> funcArgList;

    ASTFuncDecl(string lit_type, string id, ASTBlockStat *_block) : lit_type(lit_type), id(id), block(_block) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTFuncCall : public ASTnode
{
public:
    string id;

    vector<ASTExpr*> funcArgList;
    ASTFuncCall(string id) : id(id) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};


// Expr
class ASTExpr : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprUnary : public ASTExpr
{
public:
    string unary_op;
    ASTExpr *exp;

    ASTExprUnary(string unary_op, ASTExpr *_exp) : unary_op(unary_op), exp(_exp) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprBinary : public ASTExpr
{
public:
    string bin_operator;
    ASTExpr *left;
    ASTExpr *right;

    ASTExprBinary(std::string op, ASTExpr *_left, ASTExpr *_right) : bin_operator(op), left(_left), right(_right) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprTernary : public ASTExpr
{
public:
    ASTExpr *first;
    ASTExpr *second;
    ASTExpr *third;

    ASTExprTernary(ASTExpr *_first, ASTExpr *_second, ASTExpr *_third) : first(_first), second(_second), third(_third) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprInt : public ASTExpr
{
public:
    int intlit;

    ASTExprInt(int intlit) : intlit(intlit) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprFloat : public ASTExpr
{
public:
    float floatlit;

    ASTExprFloat(float floatlit) : floatlit(floatlit) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprChar : public ASTExpr
{
public:
    char charlit;

    ASTExprChar(char charlit) : charlit(charlit) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprBool : public ASTExpr
{
public:
    bool boollit;

    ASTExprBool(bool boollit) : boollit(boollit) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprString : public ASTExpr
{
public:
    string stringlit;

    ASTExprString(string stringlit) : stringlit(stringlit) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprVar : public ASTExpr
{
public:
    ASTVariable *var;

    ASTExprVar(ASTVariable *var) : var(var) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprFuncCall : public ASTExpr
{
public:
    ASTFuncCall *func_call;

    ASTExprFuncCall(ASTFuncCall *_func_call) : func_call(_func_call) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};


// Stat
class ASTStat : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatVarAssign : public ASTStat
{
public:
    ASTVariable *var;
    ASTExpr *exp;

    ASTStatVarAssign(ASTVariable *_var, ASTExpr *_exp) : var(_var), exp(_exp) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatVarDecl : public ASTStat
{
public:
    ASTVariableDecl *var_decl;

    ASTStatVarDecl(ASTVariableDecl *_var_decl) : var_decl(_var_decl) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatBlock : public ASTStat
{
public:
    ASTBlockStat *block;

    ASTStatBlock(ASTBlockStat *_block) : block(_block) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatFuncCall : public ASTStat
{
public:
    ASTFuncCall *func_call;

    ASTStatFuncCall(ASTFuncCall *_func_call) : func_call(_func_call) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatReturn : public ASTStat
{
public:
    ASTExpr *return_expr;

    ASTStatReturn(ASTExpr *_return_expr) : return_expr(_return_expr) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatLoopControl: public ASTStat
{
public:
    string control_stat;

    ASTStatLoopControl(string control_stat) : control_stat(control_stat) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatWhile : public ASTStat
{
public:
    ASTExpr *exp;
    ASTBlockStat *block;

    ASTStatWhile(ASTExpr *_exp, ASTBlockStat *_block) : exp(_exp), block(_block) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatIf : public ASTStat
{
public:
    vector<ASTExpr *> exprList;
    vector<ASTBlockStat *> blockList;

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatFor : public ASTStat
{
public:
    ASTVariableDecl *var_decl;
    ASTVariable *init_var;
    ASTExpr *init_expr;
    ASTExpr *cond_expr;
    ASTVariable *loop_var;
    ASTExpr *loop_expr;
    ASTBlockStat *block;

    ASTStatFor(ASTVariableDecl *var_decl, ASTVariable *init_var, ASTExpr *init_expr, ASTExpr *cond_expr, ASTVariable *loop_var, ASTExpr *loop_expr, ASTBlockStat *block) 
        : var_decl(var_decl), init_var(init_var), init_expr(init_expr), cond_expr(cond_expr), loop_var(loop_var), loop_expr(loop_expr), block(block) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTContext
{
public:
    ASTnode *root;

    ~ASTContext()
    {
        clearAST();
    }

    /// free all saved expression trees
    void clearAST()
    {
        delete root;
    }
};
