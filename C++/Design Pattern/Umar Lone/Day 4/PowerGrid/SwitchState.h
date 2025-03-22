#ifndef SWITCHSTATE_H
#define SWITCHSTATE_H


class SwitchState
{
public:
    SwitchState() = default;
    virtual SwitchState* switchon() = 0;
    virtual SwitchState* switchoff() = 0;
    ~SwitchState() = default;
};

#endif // SWITCHSTATE_H
