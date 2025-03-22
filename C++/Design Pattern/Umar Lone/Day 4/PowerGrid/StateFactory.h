#ifndef CSTATEFACTORY_H
#define CSTATEFACTORY_H

#include <string>

class SwitchState;

class CStateFactory
{

public:
    CStateFactory() = default;
    //Registry of singleton
    static SwitchState* GetStateInstance(std::string state_name);
};

#endif // CSTATEFACTORY_H
