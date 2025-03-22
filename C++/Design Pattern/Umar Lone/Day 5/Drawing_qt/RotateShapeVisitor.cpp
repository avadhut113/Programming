#include "RotateShapeVisitor.h"
#include <iostream>
#include "Shape.h"

RotateShapeVisitor::RotateShapeVisitor(int degree) : m_Degree(degree)
{

}

void RotateShapeVisitor::CircleRotate()
{
    std::cout << " Rotating Circle" << std::endl;
}

void RotateShapeVisitor::LineRotate()
{
    std::cout << " Rotating Circle" << std::endl;
}

void RotateShapeVisitor::RectangleRotate()
{
    std::cout << " Rotating Circle" << std::endl;
}

void RotateShapeVisitor::Operation(Shape* shape)
{

}
