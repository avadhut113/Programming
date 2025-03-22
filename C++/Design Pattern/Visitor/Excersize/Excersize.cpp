#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Value;
class AdditionExpression;
class MultiplicationExpression;

struct ExpressionVisitor
{
    virtual void accept(Value& de) =0;
    virtual void accept(AdditionExpression& ae) =0;
    virtual void accept(MultiplicationExpression& se) =0;
};

struct Expression
{
    virtual void visit(ExpressionVisitor& ev) = 0;
};

struct Value : Expression
{
    int value;

    Value(int value) : value(value) {}

    void visit(ExpressionVisitor& ev) override {
        ev.accept(*this);
    }
};

struct AdditionExpression : Expression
{
    Expression& lhs, & rhs;

    AdditionExpression(Expression& lhs, Expression& rhs) : lhs(lhs), rhs(rhs) {}

    ~AdditionExpression() {
    }
    void visit(ExpressionVisitor& ev) override {
        ev.accept(*this);
    }
};

struct MultiplicationExpression : Expression
{
    Expression& lhs, & rhs;

    MultiplicationExpression(Expression& lhs, Expression& rhs)
        : lhs(lhs), rhs(rhs) {}

    void visit(ExpressionVisitor& ev) override {
        ev.accept(*this);
    }
};

class ExpressionPrinter : public ExpressionVisitor
{
    std::ostringstream oss;
public:
    void accept(Value& de) override;
    void accept(AdditionExpression& ae) override;
    void accept(MultiplicationExpression& se) override;

    std::string str() const {
        return oss.str();
    }
};

void ExpressionPrinter::accept(Value& de)
{
    oss << de.value;
}

void ExpressionPrinter::accept(AdditionExpression& ae)
{
    bool need_brace = dynamic_cast<AdditionExpression*>(&ae);
    if (need_brace) oss << "(";
    ae.lhs.visit(*this);
    oss << "+";
    ae.rhs.visit(*this);
    if (need_brace) oss << ")";
}

void ExpressionPrinter::accept(MultiplicationExpression& se)
{
    /*bool need_brace = dynamic_cast<MultiplicationExpression*>(&se);
    if (need_brace) oss << "(";*/
    se.lhs.visit(*this);
    oss << "*";
    se.rhs.visit(*this);
    /*if (need_brace) oss << ")";*/
}

int main()
{
    /*Value v1{ 1 }, v2{ 2 }, v3{ 3 }, v4{4};
    MultiplicationExpression m1{ v1,v2 }, m2{ v3,v4 };
    AdditionExpression add{ m1,m2 };

    ExpressionPrinter ep;
    ep.accept(add);

    cout << ep.str() << std::endl;*/

    Value v2{ 2 };
    Value v3{ 3 };
    AdditionExpression simple{ v2,v3 };
    ExpressionPrinter ep;
    ep.accept(simple);

    cout << ep.str() << std::endl;

    return 0;
}