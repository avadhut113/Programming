#include "SwitchOff.h"
#include "StateFactory.h"
#include <iostream>

CSwitchOff::CSwitchOff()
{

}

SwitchState *CSwitchOff::switchon()
{
    std::cout << "Lamp is glowing in white color" << std::endl;
    return CStateFactory::GetStateInstance("white");
}

SwitchState *CSwitchOff::switchoff()
{
    std::cout << "Lamp is already off" << std::endl;
    return this;
}
