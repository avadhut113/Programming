#include "Controller.h"

Controller::Controller(int min, int max): MIN{min},
                                          MAX{max} {
}

void Controller::Regulate() {
	if(m_Thermometer.GetTemperature() > MAX) {
		m_Furnace.DecreaseTemperature() ;
	}else if(m_Thermometer.GetTemperature() < MIN) {
		m_Furnace.IncreaseTemperature() ;
	}
}
