#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution150 {
    bool isOperator(std::string op) {
        return op == "+" || op == "-" || op == "*" || op == "/";
    }

    int StringToOperand(std::string opr) {
        if (opr == "+") return 0;
        if (opr == "-") return 1;
        if (opr == "/") return 2;
        if (opr == "*") return 3;

        return -1;
    }
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;

        for (auto& token : tokens) {
            if (isOperator(token)) {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();

                int currRes = 0;

                switch (StringToOperand(token)) {
                case 0: currRes = op1 + op2; break;
                case 1: currRes = op1 - op2; break;
                case 2: currRes = op1 / op2; break;
                case 3: currRes = op1 * op2; break;
                }

                stk.push(currRes);
            }
            else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};

void test150()
{
    Solution150 sl;

    std::vector<std::string> v = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    std::cout << sl.evalRPN(v);
}