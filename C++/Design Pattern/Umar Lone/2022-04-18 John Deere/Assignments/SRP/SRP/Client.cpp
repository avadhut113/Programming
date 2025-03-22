#include "Client.h"

#include <iostream>

void Client::UseCircle() {
	m_pCircle = new Circle{{0, 0}, {100, 100}} ;
	std::cout << "Radius:" << m_pCircle->GetRadius() << '\n' ;
	std::cout << "Area:" << m_pCircle->GetArea() << '\n' ;
	std::cout << "Diameter:" << m_pCircle->GetDiameter() << '\n' ;
}
