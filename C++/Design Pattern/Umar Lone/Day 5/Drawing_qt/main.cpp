#include <iostream>

#include "Canvas.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include "RotateShapeVisitor.h"

int main() {

    std::vector<Shape* > shapes;

	Canvas canvas ;
    shapes.emplace_back(new Line{}) ;
    shapes.emplace_back(new Rectangle{}) ;
    shapes.emplace_back(new Line{}) ;
    shapes.emplace_back(new Circle{}) ;
    shapes.emplace_back(new Rectangle{}) ;

    RotateShapeVisitor rotate{45};
    for(const auto& shape : shapes) {

        shape->accept(&rotate);
    }

    //canvas.Render() ;
}
