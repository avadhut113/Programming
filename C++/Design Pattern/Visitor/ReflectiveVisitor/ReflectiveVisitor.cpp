// InstrusiveVisitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

class Expression
{
public:
    virtual ~Expression() = default;
};

class DoubleExpression : public Expression
{
    double val;
public:
    DoubleExpression(double val) : val{ val } {

    }
    double GetVale() const {
        return val;
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
};

class ExpressionPrinter
{
    std::ostringstream oss;
public:
    ExpressionPrinter() = default;
    ~ExpressionPrinter() = default;
    void print(Expression* e) {
        if (auto de = dynamic_cast<DoubleExpression*>(e)) {
            oss << de->GetVale();
        } 
        else if (auto ae = dynamic_cast<AdditionExpression*>(e)) {
            oss << "(";
            print(ae->GetLeft());
            oss << "+";
            print(ae->GetRight());
            oss << ")";
        }
    }

    std::string str() const { return oss.str(); }
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

    ExpressionPrinter ep;
    ep.print(e);
    std::cout << ep.str() << std::endl;

    delete e;

    return 0;
}
