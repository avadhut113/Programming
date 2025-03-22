// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct Token
{
    int value;

    Token(int value) : value(value) {}
};

struct Memento
{
    vector<shared_ptr<Token>> tokens;
};

struct TokenMachine
{
    vector<shared_ptr<Token>> tokens;

    Memento add_token(int value)
    {
        return add_token(make_shared<Token>(value));
    }

    // adds the token to the set of tokens and returns the
    // snapshot of the entire system
    Memento add_token(const shared_ptr<Token>& token)
    {
        tokens.push_back(token);
        return Memento{ tokens };
    }

    // reverts the system to a state represented by the token
    void revert(const Memento& m)
    {
        tokens = m.tokens;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

