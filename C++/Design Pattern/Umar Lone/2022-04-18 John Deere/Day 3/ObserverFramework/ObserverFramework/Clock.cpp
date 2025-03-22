#include "Clock.h"

#include <iostream>

void Clock::OnUpdate(void* p) {
	std::cout << "Update notification received\n" ;
}
