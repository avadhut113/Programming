// Factorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int Fact_recur(int n)
{
    if (n == 0)
        return 1;
    else
        return Fact_recur(n - 1) * n;
}

int Fact_loop(int n)
{
    int sum = 1;
    for (int i = 1; i <= n; i++)
        sum *= i;

    return sum;
}

int main()
{
    std::cout << "Recursion : " << Fact_recur(5) << std::endl; // Time complexity = O(n) Space Complexity = O(n)

    std::cout << "Loop : " << Fact_loop(5) << std::endl;    // Time complexity = O(n) Space Complexity = O(1)

}
