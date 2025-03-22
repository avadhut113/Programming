// 69. Sqrt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int ReturnApproxSqrt(int num)
{
    int sqrt = 0;
    int subtract = 1;

    while (num >= subtract)
    {
        num = num - subtract;
        subtract += 2;
        sqrt++;
    }
    return sqrt;
}

int Sqrt(int num)
{
    int squareroot = 0;

    while (squareroot * squareroot < num) {
        squareroot += 1;
    }

    if (squareroot * squareroot != num) --squareroot;

    return squareroot;
}

double mySqrt(int x) {
    if (x == 0) return 0;
    int left = 1;
    int right = x / 2 + 1;
    double res;

    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if (mid <= x / mid) {
            left = mid + 1;
            res = mid;
        }
        else {
            right = mid - 1;
        }
    }

    return res;
}

int test()
{
    std::cout << ReturnApproxSqrt(15) << std::endl;
    std::cout << ReturnApproxSqrt(63) << std::endl;
    std::cout << ReturnApproxSqrt(101) << std::endl;
    std::cout << ReturnApproxSqrt(143) << std::endl;

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "Sqrt of " << std::endl;

    std::cout << Sqrt(15) << std::endl;
    std::cout << Sqrt(63) << std::endl;
    std::cout << Sqrt(101) << std::endl;
    std::cout << Sqrt(143) << std::endl;

    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "Sqrt of " << std::endl;

    std::cout << mySqrt(15) << std::endl;
    std::cout << mySqrt(63) << std::endl;
    std::cout << mySqrt(101) << std::endl;
    std::cout << mySqrt(143) << std::endl;
}
