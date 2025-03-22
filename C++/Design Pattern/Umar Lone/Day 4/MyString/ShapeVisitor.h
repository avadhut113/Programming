#ifndef SHAPEVISITOR_H
#define SHAPEVISITOR_H


class ShapeVisitor
{
public:
    ShapeVisitor();
    virtual void visit() = 0;
};

#endif // SHAPEVISITOR_H
