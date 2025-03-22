#pragma once
#include "ArrayStack.hpp"
#include <string>


//"{()(){({})}()}"
bool isBalanced(const std::string expression)
{
	Stack<char> stack(expression.size());

	for (const auto& c : expression) {
		switch (c) {
		case '(': stack.push('(');
			break;
		case '{': stack.push('{');
			break;
		case '[': stack.push('[');
			break;
		case ')': if (stack.IsEmpty() || stack.top() != '(') 
					return false;
				  else 
					stack.pop();
			break;
		case '}': if (stack.IsEmpty() || stack.top() != '{') 
					return false;
				  else 
					stack.pop();
			break;
		case ']': if (stack.IsEmpty() || stack.top() != '[')
			return false;
				else
					stack.pop();
			break;
		default:
			stack.push(c);
			break;
		}
	}
	if (!stack.IsEmpty())
		return false;

	return true;
}


