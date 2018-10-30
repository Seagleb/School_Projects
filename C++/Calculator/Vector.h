#ifndef _Vector_h_
#define _Vector_h_
#include <iostream>
#include <stdlib.h>
using namespace std;


class Vector
{
private:
	float vect[3];

public:
	// Constructor
	Vector() { vect[0] = 0; vect[1] = 0; vect[2] = 0;};

	void operator=(const Vector &);

	// Print method
	void Print();
	// Overloaded addition operator
	Vector operator+(const Vector &);
	Vector operator-(const Vector &);
	Vector operator/(const Vector &);
	Vector operator*(const Vector &);

	// Access methods
	void setVector(int, float);

	float getVector(int);
};

#endif
