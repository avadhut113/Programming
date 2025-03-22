#include "Lamp.h"

#include <iostream>

void Lamp::SwitchOn() {
	std::cout << "[ON]" ;
	switch(m_State) {
	case Off:
		std::cout << "Lamp glows in White Color\n" ;
		m_State = White ;
		break ;
	case Yellow:
		std::cout << "Lamp is already on\n" ;
		break ;
	case White:
		std::cout << "Lamp glows in Yellow Color\n" ;
		m_State = Yellow ;
		break ;
	}
}

void Lamp::SwitchOff() {
	std::cout << "[OFF]" ;
	switch(m_State) {
	case Off:
		std::cout << "Lamp is already off\n" ;
		break ;
	case White:
		std::cout << "Lamp is switched off\n" ;
		m_State = Off ;
		break ;
	case Yellow:
		std::cout << "Lamp glows in White color\n" ;
		m_State = White ;
	}
}
