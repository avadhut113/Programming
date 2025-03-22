#pragma once
#include <iostream>

using namespace std;

template <int N>
struct Sum1toN
{
public:
    static constexpr int sum = N + Sum1toN<N - 1>::sum;
};

template <>
struct Sum1toN<1>
{
public:
    static constexpr int sum = 1;
};

template <int N>
class PrintOneToN {
public:

    static void print()
    {
        PrintOneToN<N - 1>::print();

        // Note that this is not recursion
        cout << N ;
    }
};

template <> 
class PrintOneToN<1> {
public:
    static void print() { std::cout << 1; }
};