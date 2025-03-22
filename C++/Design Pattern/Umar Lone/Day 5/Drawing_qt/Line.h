#pragma once
#include "Point.h"
#include "Shape.h"

class Line :
    public Shape
{
	Point m_Start{}, m_End{} ;
public:
	void Render() override;
	void Erase() override;
	void Outline() override;

	Point GetStart()const {
		return m_Start ;
	}
	Point GetEnd()const {
		return m_End; 
	}

    void accept(ShapeVisitor* visit) override;
};

