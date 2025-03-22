#include "SwitchWhite.h"
#include <iostream>
#include "StateFactory.h"


CSwitchWhite::CSwitchWhite()
{

}

SwitchState *CSwitchWhite::switchon()
{
    std::cout << "Turning lamp to Yellow state" << std::endl;
    return CStateFactory::GetStateInstance("yellow");
}

SwitchState *CSwitchWhite::switchoff()
{
    std::cout << "Switching off the Lamp" << std::endl;
    return CStateFactory::GetStateInstance("off");
}
