// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <string>
using namespace std;


struct Renderer
{
    virtual string what_to_render_as() const = 0;
};

struct Shape
{
    string name;

    Shape(Renderer r){}
};

struct Triangle : Shape
{
    Triangle(RasterTriangle rt) : Shape(rt)
    {
        name = "Circle";
    }
};

struct Square : Shape
{
    Square(RasterSquare rs): Shape(rs)
    {
        name = "Square";
    }
};

struct VectorSquare : Square
{
    string str() const
    {
        return "Drawing " + name + " as lines";
    }
};

struct RasterSquare : Square
{
    string str() const
    {
        return "Drawing " + name + " as pixels";
    }
};

// imagine e.g. VectorTriangle/RasterTriangle etc. here
struct VectorTriangle : Triangle
{
    string str() const
    {
        return "Drawing " + name + " as lines";
    }
};

struct RasterTriangle : Triangle
{
    string str() const
    {
        return "Drawing " + name + " as pixels";
    }
};



int main()
{
    Triangle(RasterRenderer()).str();
}

