// InstrusiveVisitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

class DoubleExpression;
class AdditionExpression;
class SubstractionExpression;

class ExpressionVisitor
{
public:
    virtual void visit(DoubleExpression* de) = 0;
    virtual void visit(AdditionExpression* ae) = 0;
    virtual void visit(SubstractionExpression* se) = 0;
};

class ExpressionPrinter : public ExpressionVisitor
{
    std::ostringstream oss;
public:
    void visit(DoubleExpression* de) override;
    void visit(AdditionExpression* ae) override;
    void visit(SubstractionExpression* se) override;

    std::string str() const{
        return oss.str();
    }
};

class ExpressionEvalvate : public ExpressionVisitor
{
    double result;
public:
    void visit(DoubleExpression* de) override;
    void visit(AdditionExpression* ae) override;
    void visit(SubstractionExpression* se) override;

    double GetResult() const{
        return result;
    }
};

class Expression
{
public:
    virtual void accept(ExpressionVisitor* ev) = 0;
    virtual ~Expression() = default;
};

class DoubleExpression : public Expression
{
    double val;
public:
    DoubleExpression(double val) : val{ val } {

    }
    double GetVal() const {
        return val;
    }
    void accept(ExpressionVisitor* ev) override {
        ev->visit(this);
    }
};

class AdditionExpression : public Expression
{
    Expression* left, * right;
public:
    AdditionExpression(Expression* left, Expression* right) : left{ left }, right{ right }{

    }
    Expression* GetLeft() const {
        return left;
    }
    Expression* GetRight() const {
        return right;
    }
    ~AdditionExpression() {
        delete left;
        delete right;
    }
    void accept(ExpressionVisitor* ev) override {
        ev->visit(this);
    }
};

class SubstractionExpression : public Expression
{
    Expression* left{nullptr}, * right{nullptr};
public:
    SubstractionExpression(Expression* left, Expression* right) : left{ left }, right{ right }{

    }
    Expression* GetLeft() const {
        return left;
    }
    Expression* GetRight() const {
        return right;
    }
    ~SubstractionExpression() {
        delete left;
        delete right;
    }
    void accept(ExpressionVisitor* ev) override {
        ev->visit(this);
    }
};

void ExpressionPrinter::visit(DoubleExpression* de)
{
    oss << de->GetVal();
}

void ExpressionPrinter::visit(AdditionExpression* ae)
{
    bool need_brace = dynamic_cast<AdditionExpression*>(ae);
    if (need_brace) oss << "(";
    ae->GetLeft()->accept(this);
    oss << "+";
    ae->GetRight()->accept(this);
    if (need_brace) oss << ")";
}

void ExpressionPrinter::visit(SubstractionExpression* se)
{
    bool need_brace = dynamic_cast<SubstractionExpression*>(se);
    if (need_brace) oss << "(";
    se->GetLeft()->accept(this);
    oss << "-";
    se->GetRight()->accept(this);
    if (need_brace) oss << ")";
}

void ExpressionEvalvate::visit(DoubleExpression* de)
{
    result = de->GetVal();
}

void ExpressionEvalvate::visit(AdditionExpression* ae)
{
    ae->GetLeft()->accept(this);
    double temp = result;
    ae->GetRight()->accept(this);
    result += temp;
}

void ExpressionEvalvate::visit(SubstractionExpression* se)
{
    se->GetLeft()->accept(this);
    double temp = result;
    se->GetRight()->accept(this);
    result = temp - result;
}

int main()
{
    auto e = new AdditionExpression{
            new SubstractionExpression{
                new DoubleExpression{1},
                new DoubleExpression{3}
            },
            new SubstractionExpression{
                new DoubleExpression{2},
                new SubstractionExpression{
                    new DoubleExpression{5},
                    new DoubleExpression{6}
                }
            },
    };

    ExpressionPrinter ep;
    ExpressionEvalvate ee;
    ee.visit(e);
    ep.visit(e);
    std::cout << ep.str() << " = " << ee.GetResult() << std::endl;

    return 0;
}
