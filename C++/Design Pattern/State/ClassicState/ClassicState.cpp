// ClassicState.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class LightSwitch;
class OffState;

class State 
{
public:
    State() = default;
    virtual void On(LightSwitch* Switch) { std::cout << "switch already on" << std::endl; }
    virtual void Off(LightSwitch* Switch) { std::cout << "switch already off" << std::endl; }
};

class WhiteState : public State
{
public:
    WhiteState() {
        std::cout << "Light is turned to white" << std::endl;
    }
    void Off(LightSwitch* Switch);
};

class OffState : public State
{
public:
    OffState() {
        std::cout << "Light is turned off" << std::endl;
    }

    void On(LightSwitch* Switch);
};

class LightSwitch
{
    State* m_state = nullptr;
public:
    LightSwitch() {
        m_state = new OffState();
    }
    void set_state(State* state) {
        m_state = state;
    }

    void On(){
        m_state->On(this);
    }
    void Off(){
        m_state->Off(this);
    }

    ~LightSwitch() {
        delete m_state;
    }

};

void WhiteState::Off(LightSwitch* Switch) {
    std::cout << "switch off the light" << std::endl;
    Switch->set_state(new OffState);
    delete this;
}

void OffState::On(LightSwitch* Switch) {
    std::cout << "Light is turrned to white" << std::endl;
    Switch->set_state(new WhiteState);
    delete this;
}


int main()
{
    LightSwitch ls;
    ls.On();
    ls.On();
    ls.Off();
    ls.On();
}