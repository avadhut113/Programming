#pragma once
#include "Furnace.h"
#include "Thermometer.h"

class Controller
{
	Thermometer m_Thermometer ;
	Furnace m_Furnace ;
	const int MIN ;
	const int MAX ;
public:
	Controller(int min, int max);

	void Regulate() ;
};

