#ifndef _Salesperson_h_
#define _Salesperson_h_

#include "Employee.h"

class Salesperson : public Employee
{
protected:
public:
	Salesperson(string n, float bs, int id) { name = n; baseSalary = bs; managerID = id; type = "Salesperson"; }


	float calcComission(float, float);
	float calcSalary();
};

#endif