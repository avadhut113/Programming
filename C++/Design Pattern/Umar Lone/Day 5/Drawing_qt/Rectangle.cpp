#include "Rectangle.h"
#include "ShapeVisitor.h"

#include <iostream>

void Rectangle::Render() {
	std::cout << "Rendering Rectangle...\n" ;
}

void Rectangle::Erase() {
	std::cout << "Erasing Rectangle...\n" ;
}

void Rectangle::Outline() {
    std::cout << "Setting outline for Rectangle...\n" ;
}

void Rectangle::accept(ShapeVisitor* visit)
{
    visit->Operation(this);
}

