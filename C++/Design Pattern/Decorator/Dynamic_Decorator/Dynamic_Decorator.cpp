// Dynamic_Decorator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>

class Shape
{
public:
    virtual std::string str() const = 0;
};

class Circle : public Shape
{
    float radius{ 0.0 };
public:
    Circle() = default;
    Circle(float rad) : radius(rad) {

    }

    void resize(float factor) {
        radius *= factor;
    }

    std::string str() const override {
        std::ostringstream oss;
        oss << "This is circle of radious " << radius;
        return oss.str();
    }
};


class Square : public Shape
{
    float side;
public:
    Square() = default;
    Square(float s) :side(s) {

    }
    std::string str() const override {
        std::ostringstream oss{};
        oss << "This is Squire of side " << side;
        return oss.str();
    }
};

class ColoredShape : public Shape
{
    Shape& shape;
    std::string color;
public:
    ColoredShape(Shape& shape, const std::string& color):shape(shape),color(color){}
    std::string str() const override {
        std::ostringstream oss{};
        oss << shape.str() << " has color " << color;
        return oss.str();
    }
};


class TransperantShape : public Shape
{
    Shape& shape;
    uint8_t transperancy;
public:
    TransperantShape(Shape& shape, uint8_t transperancy) : shape(shape), transperancy(transperancy) {
    }
    std::string str() const override {
        std::ostringstream oss{};
        oss << shape.str() << " has " << static_cast<float>(transperancy) / 255.f * 100.f << "% transperency";
        return oss.str();
    }
};

int main()
{
    Square squere(5.0);
    ColoredShape red_squere{ squere, "red" };

    std::cout << squere.str() << std::endl << red_squere.str() << std::endl;

    TransperantShape mySqure{ red_squere, 51 };
    std::cout << mySqure.str() << std::endl;
}
