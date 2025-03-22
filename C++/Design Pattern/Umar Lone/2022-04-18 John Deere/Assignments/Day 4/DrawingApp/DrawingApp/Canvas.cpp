#include "Canvas.h"
#include "Shape.h"
void Canvas::AddShape(Shape* s) {
	m_Shapes.push_back(s) ;
}

void Canvas::Render() {
	for(auto shape : m_Shapes) {
		shape->Render() ;
	}
}


