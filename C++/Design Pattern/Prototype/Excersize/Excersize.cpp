// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Point
{
    int x{ 0 }, y{ 0 };

    Point() {}

    Point(const int x, const int y) : x{ x }, y{ y } {}
    Point(const Point& other) : x{other.x},y{other.y}{}
};

struct Line
{
    Point* start, * end;

    Line(Point* const start, Point* const end)
        : start(start), end(end)
    {
    }

    Line(const Line& other) : start{ new Point{*other.start} }, end{ new Point{*other.end} }{}

    ~Line()
    {
        delete start;
        delete end;
    }

    Line deep_copy() const
    {
        //Line* line = new Line{*this};
        return *this;
    }
};

int main()
{
    Line 
}