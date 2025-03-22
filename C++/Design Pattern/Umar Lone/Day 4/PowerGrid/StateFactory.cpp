#include "StateFactory.h"
#include "SwitchOff.h"
#include "SwitchWhite.h"
#include "SwitchYellow.h"


SwitchState* CStateFactory::GetStateInstance(std::string state_name)
{
    if(state_name == "off")
        return &CSwitchOff::GetInstance();
    else if (state_name == "white")
        return &CSwitchWhite::GetInstance();
    else if (state_name == "yellow")
        return &CSwitchYellow::GetInstance();
    else
        return nullptr;
}
