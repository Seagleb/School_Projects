#include "Salesperson.h"

float Salesperson::calcComission(float ct, float ctsp)
{
	commissionTotal = ct + (ct * .05);
	return commissionTotal;
}

float Salesperson::calcSalary()
{
	salaryTotal = baseSalary + commissionTotal;
	return salaryTotal;
}