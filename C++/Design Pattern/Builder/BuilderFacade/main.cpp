// BuilderFacade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"
#include "OnBoardWifiNetworkBuilder.hpp"
#include <iostream>


void testNetworkBuilder()
{
    OnBoardWiFiNetwork CurrentNetwork = OnBoardWiFiNetworkBuilder(CurrentNetwork)
        .WithSignalStrength(100)
        .Build();
}

int main()
{
    Person p = Person::create().lives().at("NikhileshHomes")
        .with_postcode("411014")
        .in("Pune")
        .works().at("John Deere")
        .as_a("Senior Software Developer")
        .earning(10000);

    std::cout << p << std::endl;
    return 0;
}
