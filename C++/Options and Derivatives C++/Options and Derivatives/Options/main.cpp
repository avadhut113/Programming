// Options.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "GenericOption.h"
#include <iostream>

using namespace std;

int main()
{
    GenericOption option(Option_Type::put, 100.0, 1.1);
    double price1 = 120.0;
    double value = option.valueAtExpiration(price1);
    cout << " For 100PUT, value at expiration for price "
        << price1
        << " is "
        << value << endl;
    double price2 = 85.0;
    value = option.valueAtExpiration(85.0);
    cout << " For 100PUT, value at expiration for price "
        << price2
        << " is "
        << value << endl;
    // test profitAtExpiration
    auto limit = 120.0;
    for (auto price = 80.0; price <= limit; price += 0.1)
    {
        value = option.profitAtExpiration(price);
        cout << price << ", " << value << endl;
    }
    return 0;
}
