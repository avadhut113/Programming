#ifndef CSWITCHOFF_H
#define CSWITCHOFF_H

#include "SwitchState.h"



class CSwitchOff : public SwitchState
{
    CSwitchOff();
public:

    SwitchState *switchon() override;
    SwitchState *switchoff() override;

    static CSwitchOff& GetInstance() {
        static CSwitchOff off;
        return off;
    }

    ~CSwitchOff() = default;

};

#endif // CSWITCHOFF_H
