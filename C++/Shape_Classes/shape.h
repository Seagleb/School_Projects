#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

using namespace std;

class shape
{
protected:
	float area;
	float height;
	float width;
public:

	float getArea() { return area; }
	float getHeight() { return height; }
	float getWidth() { return width; }

	virtual void calcArea() = 0;
	void setArea(float a) { area = a; }
	void setHeight(float h) { height = h; }
	void setWidth(float w) { width = w; }
};
#endif
