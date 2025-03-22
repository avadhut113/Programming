#ifndef ROTATESHAPEVISITOR_H
#define ROTATESHAPEVISITOR_H

#include "ShapeVisitor.h"


class RotateShapeVisitor : public ShapeVisitor
{
    int m_Degree {0};
public:
    RotateShapeVisitor() = default;
    RotateShapeVisitor(int degree);

    void CircleRotate();
    void LineRotate();
    void RectangleRotate();
    void Operation(Shape* shape);
};

#endif // ROTATESHAPEVISITOR_H
