#ifndef _Fraction_h_
#define _Fraction_h_

#include <iostream>
#include <stdlib.h>
using namespace std;


class Fraction
{
private:
	int numerator;
	int denominator;

public:

	// Constructor
	Fraction() { numerator = 0; denominator = 0; }

	// Print method
	void Print();

	// Simplify
	void Simplify();

	// Overloaded addition operator
	Fraction operator+(const Fraction &);
	Fraction operator-(const Fraction &);
	Fraction operator/(const Fraction &);
	Fraction operator*(const Fraction &);

	// Access methods
	void setNumerator(int);
	void setDenominator(int);
	int getNumerator();
	int getDenominator();
};

#endif
