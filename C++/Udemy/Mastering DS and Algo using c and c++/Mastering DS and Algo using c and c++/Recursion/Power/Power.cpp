// Power.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>

int Pow_Recur(int m, int n)
{
    if (n == 0)
        return 1;
    else {
        return Pow_Recur(m, n - 1) * m;
    }
}

int Fast_Pow_Recur(int m, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return Fast_Pow_Recur(m * m, n / 2);
    else
        return m * Fast_Pow_Recur(m * m, (n - 1) / 2);
}

int Pow_Loop(int m, int n)
{
    int pow = 1;
    for (int i = 1; i <= n; i++)
        pow *= m;

    return pow;
}

void PrintPossiblities(std::array<int,6> arr, int k)
{
    int start = 0, end = 1;
    while (start < end && (end < arr.size())) {

        std::cout << "index : " << start << " " << end << std::endl;
        if (arr[start] - arr[end] == k || arr[end] - arr[start] == k) {
            std::cout << arr[start] << " " << arr[end] << std::endl;
        } 

        if (end < arr.size()-1)
            end++;
        else {
            start++;
            end = start + 1;
        }

     }
}

int main()
{
    PrintPossiblities({ 8,12,16,4,0,20 }, 4);

    std::cout << std::endl;

    std::cout << "Recursion : " << Fast_Pow_Recur(2, 9) << std::endl; // Time complexity = O(n) Space Complexity = O(n)

    std::cout << "Recursion : " << Pow_Recur(2,9) << std::endl; // Time complexity = O(n) Space Complexity = O(n)

    std::cout << "Loop : " << Pow_Loop(2,9) << std::endl;    // Time complexity = O(n) Space Complexity = O(1)
}
