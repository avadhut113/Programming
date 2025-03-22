#include "Thermometer.h"

#include <cstdlib>

int Thermometer::GetTemperature() const {
	return rand() % 150 ;
}
