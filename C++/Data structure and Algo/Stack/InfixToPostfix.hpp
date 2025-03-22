#pragma once
#include <string>
#include <stack>

bool isOprand(const char& c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return true;

	return false;
}

int precedence(const char& c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

//a+b*c
//std::string infixToPostfix(std::string infix)
//{
//	std::stack<char> st;
//	std::string postfix(infix.size(),' ');
//	int i = 0, j = 0;
//	for (; i < infix.size();) {
//		if (isOprand(infix[i])) {
//			postfix[j++] = infix[i++];
//		}
//		else if (infix[i] == '(')
//			st.push(infix[i++]);
//		else if (infix[i] == ')') {
//			while (st.top() != '(') {
//				postfix[j++] = st.top();
//				st.pop();
//			}
//			st.pop(); // Pop '('
//		}
//		else {
//			if(st.empty()) 
//				st.push(infix[i++]);
//			else if ( precedence(infix[i]) > precedence(st.top())) 
//				st.push(infix[i++]);
//			else {
//				postfix[j++] = st.top();
//				st.pop();
//			}
//		}
//	}
//
//	while (!st.empty())
//	{
//		postfix[j++] = st.top();
//		st.pop();
//	}
//	return postfix;
//}

std::string infixToPostfix(std::string s) {
    std::stack<char> st;
    std::string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (isOprand(c))
            result += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }
        else {
            while (!st.empty() && precedence(s[i]) < precedence(st.top()) ||
                !st.empty() && precedence(s[i]) == precedence(st.top()) &&
                associativity(s[i]) == 'L') {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}