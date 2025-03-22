#ifndef CSWITCHYELLOW_H
#define CSWITCHYELLOW_H

#include "SwitchState.h"

class CSwitchYellow : public SwitchState
{
    CSwitchYellow();
public:

    SwitchState *switchon() override;
    SwitchState *switchoff() override;

    static CSwitchYellow& GetInstance() {
        static CSwitchYellow yellow;
        return yellow;
    }

    ~CSwitchYellow() = default;
};

#endif // CSWITCHYELLOW_H
