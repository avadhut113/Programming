// Static_Decorator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <concepts>

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
        oss << "This is circle of radius " << radius;
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
        oss << "This is Square of side " << side;
        return oss.str();
    }
};

class ColoredShape : public Shape
{
    Shape& shape;
    std::string color;
public:
    ColoredShape(Shape& shape, const std::string& color) :shape(shape), color(color) {}
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

//-------------------------------------------Mixin inheritance--------------------------------------------------
//perfect forwarding

template <typename T>
concept IsAShape = std::is_base_of<Shape, T>::value;

template <IsAShape T>
class coloredShape2 : public T
{
    std::string color;
public:
    coloredShape2() = default;
    
    template<typename...Args>
    coloredShape2(std::string color, Args ...args) : color(color), T(std::forward<Args>(args)...)
    {
    }
    std::string str() const override
    {
        std::ostringstream oss;
        oss << T::str() << " has a color " << color;
        return oss.str();
    }
};

template <IsAShape T> 
class TransperantShape2 : public T
{
    uint16_t transperancy{ 0 };
public:
    TransperantShape2() = default;
    template<typename ...Args>
    TransperantShape2(uint8_t transp, Args ...args) : transperancy(transp), T(std::forward<Args>(args)...)
    {
    }
    std::string str() const override {
        std::ostringstream oss{};
        oss << T::str() << " has " << static_cast<float>(transperancy) / 255.f * 100.f << "% transperency";
        return oss.str();
    }
};

int main()
{
    coloredShape2<Circle> green_circle{ "green", 5 };
    std::cout << green_circle.str() << std::endl;

    TransperantShape2<coloredShape2<Square>> blue_squere{ 51, "blue", 20 };
    std::cout << blue_squere.str() << std::endl;
} 