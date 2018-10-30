#include "shape.h"

class circle : public shape
{
private:
	float radius;
public:
	circle() { radius = 0; }
	void calcArea();
	void getDimensions();
};

void circle::calcArea()
{
	float pi = 3.14;
	area = pi * radius * radius;
	cout << "Circle Area: " << area << endl;
	return;
}

void circle::getDimensions()
{
	cout << "Enter Radius: ";
	cin >> radius;
	return;
}
