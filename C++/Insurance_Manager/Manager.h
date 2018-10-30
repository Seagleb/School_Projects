#ifndef _Manager_h_
#define _Manager_h_

#include "Employee.h"
#include <vector>

class Manager : public Employee
{
protected:
	vector<string> subordinates;
	int numSubordinates;
public:
	Manager(string n, float bs) { name = n; baseSalary = bs; type = "Manager"; }
	float calcComission(float, float);
	float calcSalary();

};

#endif