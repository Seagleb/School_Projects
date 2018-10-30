#include "Employee.h"

ostream &operator<<(ostream &strm, Employee &s)
{
	strm << "Employee ID: " << s.id << endl;
	return strm;
}
