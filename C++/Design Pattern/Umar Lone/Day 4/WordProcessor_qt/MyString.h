#include <iostream>
#include <string>


class MyString
{
    std::string m_string;
public:
    MyString();
    void AddString(std::string str);
    std::string GetString();
    void SetString(std::string str);
    void InsertString(int pos, std::string str);
};
