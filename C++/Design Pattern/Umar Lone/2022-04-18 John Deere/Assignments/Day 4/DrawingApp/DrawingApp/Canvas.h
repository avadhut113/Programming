#pragma once
#include <vector>
class Shape ;
class Canvas
{
	std::vector<Shape *> m_Shapes{} ;
public:
	void AddShape(Shape *s) ;
	void Render() ;
};

