#pragma once
#include "Renderer.h"
#include <numbers>

class Circle
{
	float m_Radius{} ;
	Renderer *m_pRender ;
	Point m_TopLeft{} ;
	Point m_BottomRight{} ;
	int m_Color{} ;
public:
	Circle(const Point& topLeft, const Point& topRight);

	float GetRadius()const;

	float GetDiameter()const;

	float GetArea()const;

	float GetCircumference()const {
		return std::numbers::pi * 2 * m_Radius ;
	}
	Point GetTopLeft()const;
	Point GetBottomRight() const ;

	void SetColor(int color) ;

	void Draw();

	void Fill();
	void Remove() ;
};

