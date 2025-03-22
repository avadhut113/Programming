#include "Circle.h"
#include "ShapeVisitor.h"

#include <iostream>
void Circle::Render() {
	std::cout << "Rendering circle...\n" ;
}

void Circle::Erase() {
	std::cout << "Erasing circle...\n" ;
}

void Circle::Outline() {
    std::cout << "Setting outline on a circle...\n" ;
}

void Circle::accept(ShapeVisitor *visit)
{
    visit->Operation(this);
}
