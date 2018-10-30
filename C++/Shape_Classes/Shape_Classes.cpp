#include <iostream>
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "shape.h"
#include <vector>

using namespace std;

int getChoice();

int main()
{
	int choice = 0;
	circle c;
	triangle t;
	rectangle r;
	vector< shape *> shapes;
	while (choice != 5)
	{
		choice = getChoice();
		switch (choice)
		{
		case 1:
			t.getDimensions();
			shapes.push_back(&t);
			break;

		case 2:
			r.getDimensions();
			shapes.push_back(&r);
			break;

		case 3:
			c.getDimensions();
			shapes.push_back(&c);
			break;

		case 4:
			for (int i = 0; i < shapes.size(); ++i)
			{
				cout << "shape " << i << ": ";
				shapes[i]->calcArea();
			}
			break;
		case 5:
			break;
		}
	}
	return 0;
};

int getChoice()
{
	int selection;
	cout << "Please create a shape or get areas" << endl;
	cout << "1 - Triangle" << endl;
	cout << "2 - Rectangle" << endl;
	cout << "3 - Circle" << endl;
	cout << "4 - Print Areas" << endl;
	cout << "5 - Exit" << endl;
	cout << endl;
	cout << "Choice: ";
	cin >> selection;
	return selection;
}