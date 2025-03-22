#include "MyString.h"

MyString::MyString()
{

}

void MyString::AddString(std::string str)
{
    m_string += str;
}

std::string MyString::GetString()
{
    return m_string;
}

void MyString::SetString(std::string str)
{
    m_string = str;
}

void MyString::InsertString(int pos, std::string str)
{
    m_string.insert(pos, str);
}
