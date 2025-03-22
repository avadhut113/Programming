#ifndef IOPERATION_H
#define IOPERATION_H

class MyString;

class IOperation
{
public:
    IOperation() = default;
    virtual void operate(MyString& str) = 0;
};

#endif // IOPERATION_H
