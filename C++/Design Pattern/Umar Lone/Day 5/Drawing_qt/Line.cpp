#include "Line.h"
#include "ShapeVisitor.h"

#include <iostream>

void Line::Render() {
	std::cout << "Rendering line...\n" ;
}

void Line::Erase() {
	std::cout << "Erasing line...\n" ;
}

void Line::Outline() {
    std::cout << "Setting outline for a line...\n" ;
}

void Line::accept(ShapeVisitor* visit)
{
    visit->Operation(this);
}


