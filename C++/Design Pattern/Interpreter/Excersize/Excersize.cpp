// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

struct Token
{
    enum Type{integer, plus, minus} type;
    string value;
    Token(Type type, const string val) : type(type), value(val){}
};



struct ExpressionProcessor
{
    map<char, int> variables;
    std::vector<Token> tokens;

    ExpressionProcessor() {
        variables.insert({ 'x',5 });
    }

    void lex(const string& expression)
    {
        for (int i = 0; i < expression.size(); i++) {
            switch (expression[i])
            {
            case '+':
                tokens.push_back(Token{ Token::plus,"+"});
                break;
            case '-':
                tokens.push_back(Token{ Token::minus,"-"});
                break;
            default:
                ostringstream buffer{};
                buffer << expression[i];
                bool isVariable{ false };
                int j = i + 1;
                while(isdigit(expression[j]) || isalpha(expression[j]))
                {
                    buffer << expression[j];
                    j++;
                    i++;
                }
                tokens.push_back(Token{ Token::integer,buffer.str() });
                    
                /*for (int j = i + 1; j < expression.size(); j++) {
                    if (isdigit(expression[j]))
                    {
                        buffer << expression[j];
                        ++i;
                    } 
                    else if(isalpha(expression[j])) {
                        isVariable = true;
                        buffer << expression[j];
                        ++i;
                    }
                    else {
                        tokens.push_back(Token{Token::integer,buffer.str()});
                        break;
                    }
                }*/
                break;
            }
        }
    }

    int calculate(const string& expression)
    {
        tokens.clear();
        lex(expression);

        int result{ 0 };
        Token::Type operation{Token::plus};
        for (auto& token : tokens) {

            switch (token.type)
            {
            case Token::integer:
            {
                int num{ 0 };
                try{
                    num = std::stoi(token.value);
                }
                catch (...) {
                    if (token.value.size() != 1)
                        num = 0;
                    else {
                        const auto itr = variables.find(token.value[0]);
                        if (itr != variables.end())
                            num = itr->second;
                        else
                            num = 0;
                    }

                }
                

                if (operation == Token::plus)
                    result += num;
                else
                    result -= num;

                break;
            }                
            case Token::minus:
                operation = Token::minus;
                break;
            case Token::plus:
                operation = Token::plus;
                break;
            }
        }
        return result;
    }
};

int main()
{
    ExpressionProcessor ep;
    std ::cout << ep.calculate("pq+1+2+xyz") << std::endl;
    std::cout << ep.calculate("1+2+3") << std::endl;
    std::cout << ep.calculate("1+2+xy") << std::endl;
    std::cout << ep.calculate("10-2-x") << std::endl;

}
