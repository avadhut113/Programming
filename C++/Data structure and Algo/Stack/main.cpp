// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ArrayStack.hpp"
#include "LLStack.hpp"
#include "ParanthesisMatching.hpp"
#include "InfixToPostfix.hpp"

void Test_ArrayStack()
{
	Stack<int> st{ 1,2,3,4,5,6,7 };
	/*st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);*/
	std::cout << st.pop() << std::endl;
	std::cout << st.pop() << std::endl;
	std::cout << st.pop() << std::endl;
	std::cout << st.pop() << std::endl;
	std::cout << st.pop() << std::endl;
	std::cout << st.pop() << std::endl;
	st.push(8);
	st.push(9);
	st.display();
}

void Test_LLStack()
{
	LLStack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	std::cout << st.pop() << std::endl;
	std::cout << st.pop() << std::endl;
	st.clear();
	std::cout << st.pop() << std::endl;
	std::cout << st << "\n";
}

void test_isBalanced()
{
	std::string _true_("True\n");
	std::string _false_("False\n");

	std::cout << (isBalanced("{()(){({})}()}") ? _true_ : _false_);
	std::cout << (isBalanced("{()(){}(){}}()") ? _true_ : _false_);
	std::cout << (isBalanced("{()(){(})}()}") ? _true_ : _false_);
	std::cout << (isBalanced("{()(){({})}()}") ? _true_ : _false_);
	std::cout << (isBalanced("{()(){({})})}[]") ? _true_ : _false_);
	std::cout << (isBalanced("()[]{}") ? _true_ : _false_);
}

void test_infixtopostfix()
{
	std::cout << infixToPostfix("a+b*c") << "\n";
	std::cout << infixToPostfix("a+b*c-d") << "\n";
	std::cout << infixToPostfix("a*b-c*d") << "\n";
	std::cout << infixToPostfix("a/b*c/d") << "\n";
	std::cout << infixToPostfix("3^(1+1)") << "\n";
}

int main()
{
	//test_isBalanced();
	test_infixtopostfix();
}

