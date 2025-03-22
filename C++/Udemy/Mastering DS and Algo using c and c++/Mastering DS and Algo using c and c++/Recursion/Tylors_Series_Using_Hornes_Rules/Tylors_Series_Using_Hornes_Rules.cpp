// Tylors_Series_Using_Hornes_Rules.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

double e_loop(int x, int n)
{
    double result = 1;
    for (; n > 0; n--) {
        result = 1 + x * result / n;
    }
    return result;
}

double e_recur(int x, int n)
{
    static double res = 1;
    if (n == 0)
        return res;

    res = 1 + x * res / n;
    return e_recur(x, n - 1);
}


int main()
{
    std::cout << "e_loop : " << e_loop(1, 10) << std::endl;

    std::cout << "e_recur : " << e_recur(1, 10) << std::endl;

}
