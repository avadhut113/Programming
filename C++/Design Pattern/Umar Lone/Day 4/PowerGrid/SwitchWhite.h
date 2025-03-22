#ifndef CSWITCHWHITE_H
#define CSWITCHWHITE_H

#include "SwitchState.h"

class CSwitchWhite : public SwitchState
{
    CSwitchWhite();
public:

    SwitchState *switchon() override;
    SwitchState *switchoff() override;

    static CSwitchWhite& GetInstance() {
        static CSwitchWhite white;
        return white;
    }

    ~CSwitchWhite() = default;
};

#endif // CSWITCHWHITE_H
