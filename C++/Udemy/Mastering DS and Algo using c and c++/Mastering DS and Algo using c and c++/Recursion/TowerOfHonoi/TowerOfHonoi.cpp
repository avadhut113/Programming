// TowerOfHonoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void TowerOfHonoi(int n, char a, char b, char c)
{
    if(n > 0) {
        TowerOfHonoi(n - 1, a, c, b);
        std::cout << "From " << a << " to " << c << std::endl;
        TowerOfHonoi(n - 1, b, a, c);
    }
}

int f(int& x, int c)
{
    c = c - 1;
    if (c == 0)
        return 1;
    x = x + 1;
    return f(x, c) * x;
}

static int i;

int fun(int n)

{

    int x = 1, k;

    if (n == 1) return x;

    for (k = 1; k < n; ++k) {
        i++;
        x = x + fun(k) * fun(n - k);
    }

    return x;

}

int main()
{
    //TowerOfHonoi(4, 'a', 'b', 'c');
    //int x = 5;
    //std::cout << f(x, 5);

    std::cout << fun(5) << std::endl;
    std::cout << i;
}

