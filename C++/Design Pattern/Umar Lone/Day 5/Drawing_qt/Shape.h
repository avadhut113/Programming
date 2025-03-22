#pragma once

class ShapeVisitor;

class Shape
{
public:
	virtual void Render()=0;
	virtual void Erase() = 0 ;
	virtual void Outline() = 0 ;

    virtual void accept(ShapeVisitor* visit) = 0;

    virtual ~Shape() = default ;
};

