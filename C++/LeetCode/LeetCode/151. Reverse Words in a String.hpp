#pragma once
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <string>

class Solution151 {
public:
    static std::string reverseWords(std::string s) {
        std::istringstream ss(s);
        std::stack<std::string> stk;
        std::string word;
        while (ss >> word) {
            stk.push(word);
        }

        std::string result;
        int count = 0;

        while (!stk.empty()) {
            result += stk.top() + " ";
            stk.pop();
        }
        return result.erase(result.size() - 1);
    }
};

void test151()
{
    std::string str = "a good   example" /*"  hello world  "*/ /*"the sky is blue"*/;
    std::cout << Solution151::reverseWords(str);
}