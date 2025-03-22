// AcyclicVisitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

using namespace std;

template<typename visitable>
struct Visitor
{
    virtual void visit(visitable& obj) = 0;
}; 

struct VisitorBase
{
    virtual ~VisitorBase() = default;
};

struct Expression
{
    virtual ~Expression() = default;
    virtual void accept(VisitorBase& e)
    {
        using EV = Visitor<Expression>;
        if (auto ev = dynamic_cast<EV*>(&e))
            ev->visit(*this);
    }
};

struct DoubleExpression : public Expression
{
    DoubleExpression(double val) : value(val) {}
    virtual ~DoubleExpression() = default;
    virtual void accept(VisitorBase& de)
    {
        using DEV = Visitor<DoubleExpression>;
        if (auto dev = dynamic_cast<DEV*>(&de))
            dev->visit(*this);
    }

    double value;
};

struct AdditionExpression : public Expression
{
    Expression* left, * right;
    AdditionExpression(Expression* l, Expression* r) : left(l), right(r) {}
    virtual ~AdditionExpression()
    {
        delete left;
        delete right;
    }
    virtual void accept(VisitorBase& ae)
    {
        using AEV = Visitor<AdditionExpression>;
        if (auto aev = dynamic_cast<AEV*>(&ae))
            aev->visit(*this);
    }
};

struct ExpressionVisitor : public VisitorBase
                        , public Visitor<DoubleExpression>
                        , public Visitor<AdditionExpression>
{
public:
    void visit(DoubleExpression& de)
    {
        oss << de.value;
    }

    void visit(AdditionExpression& ae)
    {
        oss << "(";
        ae.left->accept(*this);
        oss << "+";
        ae.right->accept(*this);
        oss << ")";
    }

    string str() const { return oss.str(); }
private:
    ostringstream oss;
};

int main()
{
    auto e = new AdditionExpression{
                    new AdditionExpression{
                        new DoubleExpression{1},
                        new DoubleExpression{2}
                    },
                    new AdditionExpression{
                        new DoubleExpression{3},
                        new DoubleExpression{4}
                    }
    };

    ExpressionVisitor ev;
    ev.visit(*e);
    cout << ev.str() << "\n";

    return 0;
}