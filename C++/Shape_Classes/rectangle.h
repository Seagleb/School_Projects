#include "shape.h"

class rectangle : public shape 
{
public:
	void calcArea();
	void getDimensions();
};

void rectangle::calcArea() 
{
	area = width * height;
	cout << "Rectangle Area: " << area << endl;
	return;
}

void rectangle::getDimensions() 
{
	cout << "Enter Width: ";
	cin >> width;
	cout << "Enter Height: ";
	cin >> height;
	return;
}
