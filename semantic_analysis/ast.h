#include <string>
#include <vector>

using namespace std;

class ASTProg;

class ASTVariable;
class ASTVariableAssign;
class ASTVariableDecl;

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

class ASTStat;
class ASTStatVarAssign;
class ASTStatVarDecl;

class ASTvisitor
{
public:
    virtual void visit(ASTProg &node) = 0;
    virtual void visit(ASTVariable &node) = 0;
    virtual void visit(ASTVariableAssign &node) = 0;
    virtual void visit(ASTVariableDecl &node) = 0;

    virtual void visit(ASTExprUnary &node) = 0;
    virtual void visit(ASTExprBinary &node) = 0;
    virtual void visit(ASTExprTernary &node) = 0;
    virtual void visit(ASTExprInt &node) = 0;
    virtual void visit(ASTExprFloat &node) = 0;
    virtual void visit(ASTExprChar &node) = 0;
    virtual void visit(ASTExprBool &node) = 0;
    virtual void visit(ASTExprString &node) = 0;
    virtual void visit(ASTExprVar &node) = 0;
    virtual void visit(ASTExpr &node) = 0;

    virtual void visit(ASTStatVarDecl &node) = 0;
    virtual void visit(ASTStatVarAssign &node) = 0;
    virtual void visit(ASTStat &node) = 0;
};

class ASTnode
{
public:
    virtual ~ASTnode()
    {
    }

    //  virtual void printPostFix() const = 0;

    virtual void accept(ASTvisitor &V) = 0;
};

class ASTProg : public ASTnode
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
    string id;
    ASTExpr *param1;
    ASTExpr *param2;

public:
    ASTVariable(string id, ASTExpr *_param1, ASTExpr *_param2) : id(id), param1(_param1), param2(_param2) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVariableAssign : public ASTnode
{
    string id;
    ASTExpr *exp;

public:
    ASTVariableAssign(string id, ASTExpr *_exp) : id(id), exp(_exp) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTVariableDecl : public ASTnode
{
    string lit_type;

public:
    vector<ASTVariable*> varList;
    vector<ASTVariableAssign*> varAssignList;
    
    ASTVariableDecl(string lit_type) : lit_type(lit_type) {}

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
    string unary_op;
    ASTExpr *exp;

public:
    ASTExprUnary(string unary_op, ASTExpr *_exp) : unary_op(unary_op), exp(_exp) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprBinary : public ASTExpr
{
    string bin_operator;
    ASTExpr *left;
    ASTExpr *right;

public:
    ASTExprBinary(std::string op, ASTExpr *_left, ASTExpr *_right) : bin_operator(op), left(_left), right(_right) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprTernary : public ASTExpr
{
    ASTExpr *first;
    ASTExpr *second;
    ASTExpr *third;

public:
    ASTExprTernary(ASTExpr *_first, ASTExpr *_second, ASTExpr *_third) : first(_first), second(_second), third(_third) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprInt : public ASTExpr
{
    int intlit;

public:
    ASTExprInt(int intlit) : intlit(intlit) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprFloat : public ASTExpr
{
    float floatlit;

public:
    ASTExprFloat(float floatlit) : floatlit(floatlit) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprChar : public ASTExpr
{
    char charlit;

public:
    ASTExprChar(char charlit) : charlit(charlit) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprBool : public ASTExpr
{
    bool boollit;

public:
    ASTExprBool(bool boollit) : boollit(boollit) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprString : public ASTExpr
{
    string stringlit;

public:
    ASTExprString(string stringlit) : stringlit(stringlit) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprVar : public ASTExpr
{
    ASTVariable *var;

public:
    ASTExprVar(ASTVariable *var) : var(var) {}

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
    ASTVariable *var;
    ASTExpr *exp;

public:
    ASTStatVarAssign(ASTVariable *_var, ASTExpr *_exp) : var(_var), exp(_exp) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatVarDecl : public ASTStat
{
    ASTVariableDecl *var_decl;

public:
    ASTStatVarDecl(ASTVariableDecl *_var_decl) : var_decl(_var_decl) {}

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
