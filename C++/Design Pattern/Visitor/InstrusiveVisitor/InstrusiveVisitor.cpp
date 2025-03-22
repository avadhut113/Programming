// InstrusiveVisitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

class Expression
{
public:
    virtual ~Expression() = default;
    virtual void print(std::ostringstream& oss) = 0;
};

class DoubleExpression : public Expression
{
    double val;
public:
    DoubleExpression(double val) : val{ val } {

    }

    void print(std::ostringstream& oss) override {
        oss << val;
    }
};

class AdditionExpression : public Expression
{
    Expression* left,* right;
public:
    AdditionExpression(Expression* left, Expression* right) : left{ left }, right{ right }{

    }
    void print(std::ostringstream& oss) override {
        oss << "(";
        left->print(oss);
        oss << "+";
        right->print(oss);
        oss << ")";
    }
    ~AdditionExpression() {
        delete left;
        delete right;
    }
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

    std::ostringstream oss;
    e->print(oss);
    std::cout << oss.str() << std::endl;

    delete e;

    return 0;
}
