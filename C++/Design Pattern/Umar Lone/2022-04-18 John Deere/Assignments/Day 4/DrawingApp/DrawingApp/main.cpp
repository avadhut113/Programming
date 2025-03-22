#include <iostream>

#include "Canvas.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"

int main() {
	Canvas canvas ;
	canvas.AddShape(new Line{}) ;
	canvas.AddShape(new Rectangle{}) ;
	canvas.AddShape(new Line{}) ;
	canvas.AddShape(new Circle{}) ;
	canvas.AddShape(new Rectangle{}) ;

	canvas.Render() ;
}
