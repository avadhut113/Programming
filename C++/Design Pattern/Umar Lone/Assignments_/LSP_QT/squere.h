#ifndef SQUERE_H
#define SQUERE_H

#include "Rectangle.h"

class Squere : public Rectangle
{
    int side;
public:
    Squere(int side);
    void SetLength(int length) override;
    void SetHeight(int height) override;
};

#endif // SQUERE_H
