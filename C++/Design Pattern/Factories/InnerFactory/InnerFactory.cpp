// FactoryMethod.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

class point
{
    float m_x = 0, m_y = 0;

    point(float x, float y) : m_x(x), m_y(y) {}

    //Inner Factory 2 (factory with singleton)
    class pointFactory
    {
    public:
        //Factory Methods
        static point NewCartesion(float x, float y) {
            return { x, y };
        }

        static point Newpolar(float r, float theta) {
            return { r * cos(theta), r * sin(theta) };
        }
    };

public:
    static pointFactory Factory; // singleton factory object

    friend std::ostream& operator<<(std::ostream& os, const point& pt) {
        os << "x=" << pt.m_x << "  y=" << pt.m_y;
        return os;
    }

    //Inner Factory 1
    /*class pointFactory
    {
    public:
        //Factory Methods
        static point NewCartesion(float x, float y) {
            return { x, y };
        }

        static point Newpolar(float r, float theta) {
            return { r * cos(theta), r * sin(theta) };
        }
    };*/
};


int main()
{
    point cartesion_pt = point::Factory.NewCartesion(5, 6);
    point polar_point = point::Factory.Newpolar(5, M_PI_4);

    std::cout << cartesion_pt << std::endl;
    std::cout << polar_point << std::endl;

}

