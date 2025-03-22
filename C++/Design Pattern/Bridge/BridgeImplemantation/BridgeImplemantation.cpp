// BridgeImplemantation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct  renderer
{
    virtual void renderer_circle(int x, int y, float radious) = 0;
};

struct  raster_rendrer : renderer
{
   void renderer_circle(int x, int y, float radious) override {
        std::cout << "rasterizing a circle of radious " << radious << std::endl;
   }
};

struct vector_renderer : renderer
{
    void renderer_circle(int x, int y, float radious) override {
        std::cout << "Drawing a circle of radious " << radious << std::endl;
    }
};


struct shape
{
protected:
    renderer& rend;
    shape(renderer& r) :rend{r} {};
public:
    virtual void draw() = 0;
    virtual void resize(float factor) = 0;
};

struct circle : shape
{
    circle(renderer& rend, int x, int y, float rad) : shape(rend), x{ x }, y{ y }, radious{ rad } {

    }
    int x, y;
    float radious;

    void draw() override {
        rend.renderer_circle(x, y, radious);
    }

    void resize(float factor) override {
        radious *= factor;
    }
};

int main()
{
    raster_rendrer rr;
    circle raster_circle{ rr, 5, 5, 5 };
    raster_circle.draw();
    raster_circle.resize(2);
    raster_circle.draw();
}
