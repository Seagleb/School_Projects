#include <iomanip>
#include "Fraction.h"
#include "Vector.h"

int getChoice();

int main()
{
	Fraction f1, f2, result;
	Vector v1, v2, vr;
	int tmpN, tmpD ,tmpN2, tmpD2;
	float flt1, flt2, fltRslt;
	float vflt1, vflt2, vflt3, v2flt1, v2flt2, v2flt3;
	int choice = 0;
	char nullSign;
	char op;
	cout << setiosflags(ios::left);

	while (choice != 4)
	{
		choice = getChoice();
		switch (choice)
		{
		case 1:
			cout << "Please Enter in format '# op #'  ex:3.1  + 2.3" << endl;
			cout << "Choices of operators include '+,-,/,*'" << endl;
			cin >> flt1 >> op >> flt2;
			if (op == '+')
			{
				fltRslt = flt1 + flt2;
				cout << flt1 << " + " << flt2 << " = " << fltRslt << endl;
			}
			else if (op == '-')
			{
				fltRslt = flt1 - flt2;
				cout << flt1 << " - " << flt2 << " = " << fltRslt << endl;
			}
			else if (op == '*')
			{
				fltRslt = flt1 * flt2;
				cout << flt1 << " * " << flt2 << " = " << fltRslt << endl;
			}
			else if (op == '/')
			{
				fltRslt = flt1 / flt2;
				cout << flt1 << " / " << flt2 << " = " << fltRslt << endl;
			}
			break;
		case 2:
			cout << "Please Enter in format 'n,n,n op n,n,n'  ex: 2,1,3 + 4,3,6" << endl;
			cout << "Choices of operators include '+,-,/,*'" << endl;
			cin >> vflt1 >> nullSign >> vflt2 >> nullSign >> vflt3 >> op >> v2flt1 >> nullSign >> v2flt2 >> nullSign >> v2flt3;
			v1.setVector(0, vflt1);
			v1.setVector(1, vflt2);
			v1.setVector(2, vflt3);
			v2.setVector(0, v2flt1);
			v2.setVector(1, v2flt2);
			v2.setVector(2, v2flt3);
			if (op == '+')
			{
				vr = v1 + v2;
				v1.Print();     cout << " + ";
				v2.Print();     cout << " = ";
				vr.Print(); cout << endl;
			}
			
			else if (op == '-')
			{
				vr = v1 - v2;
				v1.Print();     cout << " - ";
				v2.Print();     cout << " = ";
				vr.Print(); cout << endl;
			}
			else if (op == '*')
			{
				vr = v1 * v2;
				v1.Print();     cout << " * ";
				v2.Print();     cout << " = ";
				cout << vr.getVector(0) << endl;
			}
			else if (op == '/')
			{
				vr = v1 / v2;
				v1.Print();     cout << " / ";
				v2.Print();     cout << " = ";
				vr.Print(); cout << endl;
			}
			break;
		case 3:
			cout << "Please Enter in format 'n/d op n/d'  ex: 1/3 + 2/3" << endl;
			cout << "Choices of operators include '+,-,/,*'" << endl;
			cin >> tmpN >> nullSign >> tmpD >> op >> tmpN2 >> nullSign >> tmpD2;
			f1.setNumerator(tmpN);
			f1.setDenominator(tmpD);
			f2.setNumerator(tmpN2);
			f2.setDenominator(tmpD2);
			if (op == '+')
			{
				result = f1 + f2;
				result.Simplify();
				f1.Print();     cout << " + ";
				f2.Print();     cout << " = ";
				result.Print(); cout << endl;
			}
			else if (op == '-')
			{
				result = f1 - f2;
				result.Simplify();
				f1.Print();     cout << " - ";
				f2.Print();     cout << " = ";
				result.Print(); cout << endl;
			}
			else if (op == '*')
			{
				result = f1 * f2;
				result.Simplify();
				f1.Print();     cout << " * ";
				f2.Print();     cout << " = ";
				result.Print(); cout << endl;
			}
			else if (op == '/')
			{
				result = f1 / f2;
				result.Simplify();
				f1.Print();     cout << " / ";
				f2.Print();     cout << " = ";
				result.Print(); cout << endl;
			}
			break;
		case 4:
			break;
		}
	}
}

int getChoice()
{
	int selection;
	cout << "================" << endl;
	cout << "Basic Calculator" << endl;
	cout << "================" << endl;
	cout << "Please select from the following" << endl;
	cout << "1 - Floating-point" << endl;
	cout << "2 - Vector" << endl;
	cout << "3 - Fraction" << endl;
	cout << "4 - Exit" << endl;
	cout << endl;
	cout << "Choice: ";
	cin >> selection;
	return selection;
}