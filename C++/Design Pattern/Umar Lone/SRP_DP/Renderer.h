#pragma once
struct Point {
	int x,y ;
};
class Renderer
{
public:
	void Draw(const Point *points, int color) ;
	void Erase(const Point *points) ;
};

