#pragma once
#include "Point.h"
#include "Shape.h"
class Circle :
    public Shape
{
	Point m_Position{} ;
	float m_Radius ;
public:
	void Render() override;
	void Erase() override;
	void Outline() override;

	Point GetPosition()const {
		return m_Position ;
	}
	float GetRadius()const{
		return m_Radius ;
	}

    void accept(ShapeVisitor* visit) override;
};

