// Fabonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define MAX_SIZE = 100

int Fab_Loop(int n)
{
    if (n <= 1)
        return n;

    int num1 = 0, num2 = 1, res;
    for (int i = 2; i <= n; i++) {
        res = num1 + num2;
        num1 = num2;
        num2 = res;
    }
    return res;
}

int Fab_Recur(int n)
{
    if (n <= 1)
        return n;

    return Fab_Recur(n - 2) + Fab_Recur(n - 1);
}

int Fab_Memoaization(int n)
{
    static int arr[100];

    if (n <= 1) {
        arr[n] = n;
        return n;
    }

    if (arr[n - 1] == 0)
        arr[n - 1] = Fab_Memoaization(n - 1);

    if (arr[n - 2] == 0)
        arr[n - 2] = Fab_Memoaization(n - 2);

    return arr[n - 1] + arr[n - 2];
}

int main()
{
    std::cout << "Fab_Loop : " << Fab_Loop(7) << std::endl;

    std::cout << "Fab_Loop : " << Fab_Recur(7) << std::endl;

    std::cout << "Fab_Loop : " << Fab_Memoaization(7) << std::endl;

}
