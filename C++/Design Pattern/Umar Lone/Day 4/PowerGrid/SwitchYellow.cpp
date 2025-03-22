#include "SwitchYellow.h"
#include "StateFactory.h"
#include <iostream>

CSwitchYellow::CSwitchYellow()
{

}

SwitchState *CSwitchYellow::switchon()
{
    std::cout << " Already in yellow state " << std::endl;
    return this;
}

SwitchState *CSwitchYellow::switchoff()
{
    std::cout << " Turning lamp to white state " << std::endl;
    return CStateFactory::GetStateInstance("white");
}
