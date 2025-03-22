#ifndef LAMPCONTROLLER_H
#define LAMPCONTROLLER_H

#include "SwitchState.h"


class LampController
{
    SwitchState* m_state = nullptr;

public:
    LampController() = default;
    void SetInitialState();
    void switchon();
    void switchoff();
};

#endif // LAMPCONTROLLER_H
