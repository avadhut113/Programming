#include "squere.h"

Squere::Squere(int side):Rectangle(side,side)
{

}

void Squere::SetLength(int length)
{
    Rectangle::SetLength(length);
    Rectangle::SetHeight(length);
}
