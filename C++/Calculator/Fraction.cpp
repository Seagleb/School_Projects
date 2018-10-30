#include "Fraction.h"

// Set/Get functions
void Fraction::setNumerator(int n)
{
	numerator = n;
}
void Fraction::setDenominator(int d)
{
	denominator = d;
}
int Fraction::getNumerator()
{
	return numerator;
}
int Fraction::getDenominator()
{
	return denominator;
}

// Add fractions
Fraction Fraction::operator+(const Fraction &f2)
{
	Fraction f3;

	f3.numerator = numerator * f2.denominator + denominator * f2.numerator;
	f3.denominator = denominator * f2.denominator;

	return f3;
}
Fraction Fraction::operator-(const Fraction &f2)
{
	Fraction f3;

	f3.numerator = numerator * f2.denominator - denominator * f2.numerator;
	f3.denominator = denominator * f2.denominator;

	return f3;
}
Fraction Fraction::operator*(const Fraction &f2)
{
	Fraction f3;

	f3.numerator = numerator * f2.numerator;
	f3.denominator = denominator * f2.denominator;

	return f3;
}
Fraction Fraction::operator/(const Fraction &f2)
{
	Fraction f3;

	f3.numerator = numerator * f2.denominator;
	f3.denominator = denominator * f2.numerator;

	return f3;
}

/* Simplify fraction */
void Fraction::Simplify()
{
	int a, b, c, gcd;
	if (denominator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	};
	a = abs(numerator);
	b = abs(denominator);
	c = a % b;
	while (c)
	{
		a = b;
		b = c;
		c = a % b;
	}
	gcd = b;
	numerator /= gcd;
	denominator /= gcd;
}

// Print fraction
void Fraction::Print()
{
	cout << numerator << "/" << denominator;
}
