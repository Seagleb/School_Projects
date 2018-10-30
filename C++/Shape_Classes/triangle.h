#include "shape.h"

class triangle : public shape
{
private:
	float base;
public:
	triangle()
	{
		base = 0;
	}
	void calcArea();
	void getDimensions();
};

void triangle::calcArea()
{
	area = base * height*0.5;
	cout << "Triangle Area: " << area << endl;
	return;
}

void triangle::getDimensions()
{
	cout << "Enter Base: ";
	cin >> base;
	cout << "Enter Height: ";
	cin >> height;
	return;
}
