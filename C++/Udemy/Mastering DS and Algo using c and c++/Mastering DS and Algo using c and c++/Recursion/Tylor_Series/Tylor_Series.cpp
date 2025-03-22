// Tylor_Series.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

double e_recr(int x, int n)
{
    static double p = 1, f = 1;
    double res = 0;
    if (n == 0)
        return 1;

    res = e_recr(x, n - 1);
    p = p * x;
    f = f * n;
    return res + p / f;
}

double e_loop(int x, int n)
{
    double result = 1;
    double num = 1;
    double den = 1;

    for (int i = 1; i <= n; i++) {
        num *= x;
        den *= i;

        result += (num / den);
    }
    return result;
}

int main()
{
    std::cout << "e_recr : " << e_recr(2,10) << std::endl;

    std::cout << "e_loop : " << e_loop(2, 10) << std::endl;

}

