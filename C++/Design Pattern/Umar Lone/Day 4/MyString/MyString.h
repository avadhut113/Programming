#ifndef MYSTRING_H
#define MYSTRING_H


#include <iostream>
#include <string>
#include "IOperation.h"


class MyString
{
    std::string m_string;
public:
    MyString();
    void AddString(std::string str);
    std::string GetString();
    void SetString(std::string str);
    void InsertString(int pos, std::string str);
    char& operator[](int i) {
        return m_string[i];
    }
    int GetLength() { return m_string.length(); }

    void accept(IOperation* operation) { operation->operate(*this); }
};


#endif // MYSTRING_H
