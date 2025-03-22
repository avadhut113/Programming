#ifndef SHAPEVISITOR_H
#define SHAPEVISITOR_H

class Shape;

class ShapeVisitor
{
public:
    ShapeVisitor() = default;

    virtual void Operation(Shape* shape) = 0;

    virtual void CircleRotate() = 0;
    virtual void LineRotate() = 0;
    virtual void RectangleRotate() = 0;

};

#endif // SHAPEVISITOR_H
