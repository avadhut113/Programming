// Combination.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

int nCr_Formula(int n, int r)
{
    if (r == 0 || n == r)
        return 1;

    int nFact = factorial(n);
    int rFact = factorial(r);
    int nrFacr = factorial(n - r);

    return nFact / (rFact * nrFacr);
}

int nCr_Recur(int n, int r)
{
    if (r == 0 || n == r)
        return 1;

    return nCr_Recur(n - 1, r - 1) + nCr_Recur(n - 1, r);
}

int main()
{

    std::cout << "nCr_Recur : " << nCr_Recur(7,3) << std::endl;

    std::cout << "nCr_Formula : " << nCr_Formula(7,3) << std::endl;
}