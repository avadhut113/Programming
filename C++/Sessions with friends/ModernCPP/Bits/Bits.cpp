// Bits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <Bits.h>
#include <string>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;

bool isBinary(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](char c) {
        return c == '0' || c == '1';
     });
}

int binarytodecimal(std::string num)
{
    if (!isBinary(num)) {
        std::cout << "Invalid Binary number" <<std::endl;
        return -1;
    }

    num.reserve();
    int decimal{ 0 };
    //std::bitset<1> flag(0);
    int pow = 0;
    for (auto ch : num) {    
        decimal = ch == '1' ? decimal + std::pow(2, pow) : decimal;
        pow++;
    }

    /*return std::for_each(num.begin(), num.end(), [&decimal,&pow](const char c) {
                decimal = c == '1'? decimal + std::pow(2, pow) : decimal ;
                pow++;
                return decimal;
            });*/

    return decimal;
}

void decimaltobinay(int num)
{
    if (num <= 0)
        return;

    int rem = num % 2;
    decimaltobinay(num / 2);
    std::cout << rem;
}

int main()
{
    decimaltobinay(255);
    std::cout << std::endl;
    std::cout<<binarytodecimal("11111111")<<std::endl;
    return 0;
}