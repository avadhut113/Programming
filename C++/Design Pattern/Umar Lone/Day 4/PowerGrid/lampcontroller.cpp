#include "lampcontroller.h"
#include "iostream"
#include "SwitchOff.h"
#include "SwitchWhite.h"
#include "StateFactory.h"

void LampController::SetInitialState()
{
    m_state = CStateFactory::GetStateInstance("off");
}

void LampController::switchon()
{
//    if(m_button == 0) {
//        m_button++;
//        std::cout << "Lamp is white" << std::endl;
//    } else if(m_button == 1) {
//        m_button++;
//        std::cout << "Lamp is Yellow" << std::endl;
//    } else {
//        std::cout << "Lamp is already on" << std::endl;
//    }

    m_state = m_state->switchon();

}

void LampController::switchoff()
{
    /*
    if(m_button == 2) {
        m_button--;
        std::cout << "Lamp is white" << std::endl;
    } else if (m_button == 1) {
        m_button--;
        std::cout << "Lamp is off" << std::endl;
    } else {
        std::cout << "Lamp is already off" << std::endl;
    }*/

    m_state = m_state->switchoff();
}
