#include "Vector.h"

// Set/Get functions
void Vector::setVector(int n, float f)
{
	vect[n]=f;
}
float Vector::getVector(int n)
{
	return vect[n];
}
void Vector::operator=(const Vector &a)
{
	// If not self-copy
	if (this != &a)
	{
		// Member-wise copy
		vect[0] = a.vect[0];
		vect[1] = a.vect[1];
		vect[2] = a.vect[2];
	}
}

// Add Vectors
Vector Vector::operator+(const Vector &f2)
{
	Vector f3;
	f3.vect[0] = vect[0] + f2.vect[0];
	f3.vect[1] = vect[1] + f2.vect[1];
	f3.vect[2] = vect[2] + f2.vect[2];
	return f3;
}

Vector Vector::operator-(const Vector &f2)
{
	Vector f3;
	f3.vect[0] = vect[0] - f2.vect[0];
	f3.vect[1] = vect[1] - f2.vect[1];
	f3.vect[2] = vect[2] - f2.vect[2];
	return f3;
}

Vector Vector::operator*(const Vector &f2)
{
	Vector f3;
	f3.vect[0] = ((vect[0] * f2.vect[0]) + (vect[1] * f2.vect[1]) + (vect[2] * f2.vect[2]));
	return f3;
}

Vector Vector::operator/(const Vector &f2)
{
	Vector f3;
	f3.vect[0] = (vect[1] * f2.vect[0]) - (f2.vect[1] * vect[2]);
	f3.vect[1] = -((vect[0] * f2.vect[2]) - (f2.vect[0] * vect[2]));
	f3.vect[2] = (vect[0] * f2.vect[1]) - (f2.vect[0] * vect[1]);
	return f3;
}

// Print Vector
void Vector::Print()
{
	for (int i = 0; i < 3; i++)
	{ 
		cout << vect[i] << " "; 
	}
}
