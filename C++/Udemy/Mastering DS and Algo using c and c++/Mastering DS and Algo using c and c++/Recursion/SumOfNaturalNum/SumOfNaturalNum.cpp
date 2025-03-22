// SumOfNaturalNum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int Sum(int n)
{
    if (n == 0)
        return 0;
    else {
        return Sum(n - 1) + n;
    }
}

int Sum_Formula(int n) 
{
    return n*(n + 1) / 2;
}

int Sum_Loop(int n)
{
    int sum_loop = 0;
    for (int i = 0; i <= n; i++) {
        sum_loop += i;
    }
    return sum_loop;
}

int main()
{
    std::cout << "Recursion : " << Sum(100) << std::endl;   // Time complexity = O(n) Space Complexity = O(n)

    std::cout << "Formula : " << Sum_Formula(100) << std::endl; //Time complexity = O(1) Space Complexity = O(1)

    std::cout << "Loop : " << Sum_Loop(100) << std::endl;   //Time complexity = O(n) Space Complexity = O(1)

}
