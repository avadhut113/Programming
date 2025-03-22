#include <iostream>
#include <string>

using namespace std;

class Solution1021 {
public:
    static string removeOuterParentheses(string s) {
        string res;
        int count = 0;

        for (char c : s) {
            if (c == '(' && count++ > 0)
                res += c;

            if (c == ')' && count-- > 1)
                res += c;
        }
        return res;
    }
};

void test1021()
{
    std::cout << Solution1021::removeOuterParentheses("((())())(())") << "\n";
}