// ValidParanthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid1(string s) {
        bool valid = false;
        stack<char> st;
        for (auto ch : s) {
            switch (ch) {
            case ')' :
                if (st.top() == '(')
                    st.pop();
                else
                    st.push(')');
                break;

            case ']':
                if (st.top() == '[')
                    st.pop();
                else
                    st.push(']');
                break;

            case '}':
                if (st.top() == '{')
                    st.pop();
                else
                    st.push('}');
                break;

            default:
                st.push(ch);
                break;
            }
        }
        if (st.empty())
            valid = true;

        return valid;
    }

    bool isValid2(string s) {
        stack<char> t;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                t.push(s[i]);
            }
            else if (s[i] == ')') {
                if (i == 0 || t.empty() || t.top() != '(') {
                    return false;
                }
                t.pop();
            }
            else if (s[i] == ']') {
                if (i == 0 || t.empty() || t.top() != '[') {
                    return false;
                }
                t.pop();
            }
            else if (s[i] == '}') {
                if (i == 0 || t.empty() || t.top() != '{') {
                    return false;
                }
                t.pop();
            }
        }
        return t.empty();
    }
};

int test()
{
    Solution sl;
    cout << sl.isValid2("({[({[]})}]})");
}
