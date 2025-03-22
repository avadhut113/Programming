// AbstractFactory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DrinkFactory.h"

int main()
{
    
    DrinkFactory df;
    df.make_drink("Coffee", 2);
    df.make_drink("Tea", 3);

    df.make_drink("Pepsi", 2);
}
