#include <string>
#include <vector>

using namespace std;

class ASTProg;

class ASTExpr;
class ASTExprUnary;
class ASTExprNot;
class ASTExprBinary;
class ASTExprInt;
class ASTExprFloat;
class ASTExprChar;
class ASTExprBool;
class ASTExprString;

class ASTvisitor
{
public:
    virtual void visit(ASTProg &node) = 0;

    virtual void visit(ASTExprUnary &node) = 0;
    virtual void visit(ASTExprNot &node) = 0;
    virtual void visit(ASTExprBinary &node) = 0;
    virtual void visit(ASTExprInt &node) = 0;
    virtual void visit(ASTExprFloat &node) = 0;
    virtual void visit(ASTExprChar &node) = 0;
    virtual void visit(ASTExprBool &node) = 0;
    virtual void visit(ASTExprString &node) = 0;
    virtual void visit(ASTExpr &node) = 0;
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
    std::vector<ASTExpr *> statementList;
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

class ASTExprNot: public ASTExpr
{
    ASTExpr *exp;

public:
    ASTExprNot(ASTExpr *_exp) : exp(_exp) {}

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprBinary : public ASTExpr
{
    std::string bin_operator;
    ASTExpr *left;
    ASTExpr *right;

public:
    ASTExprBinary(std::string op, ASTExpr *_left, ASTExpr *_right) : bin_operator(op), left(_left), right(_right) {}

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
