// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <ostream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CodeBuilder
{
    std::string class_name;
    std::vector<std::pair<std::string, std::string>> class_fields;
public:
    CodeBuilder(const string& class_name) : class_name(class_name)
    {

    }

    CodeBuilder& add_field(const string& name, const string& type)
    {
        class_fields.push_back({ name,type });
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        os << "class " << obj.class_name << "\n"
            << "{\n";
        for (auto it : obj.class_fields) {
            os << "  " << it.second << " " << it.first << ";\n";
        }
        os << "};";
        return os;
    }
};

void tests()
{
    auto cb = CodeBuilder{ "Person" }.add_field("name", "string").add_field("age", "int");
    cout << cb;
}

