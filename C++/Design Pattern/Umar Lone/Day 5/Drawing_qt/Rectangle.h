#pragma once
#include "Point.h"
#include "Shape.h"

class Rectangle :
    public Shape
{
	Point m_TopLeft, m_BottomRight ;
public:
	void Render() override;
	void Erase() override;
	void Outline() override;
	Point GetTopLeft()const {
		return m_TopLeft ;
	}
	Point GetBottomRight()const {
		return m_BottomRight;
	}

    void accept(ShapeVisitor* visit) override;
};

