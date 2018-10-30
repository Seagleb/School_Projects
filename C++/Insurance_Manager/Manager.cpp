#include "Manager.h"

float Manager::calcComission(float ct,float ctsp)
{
	commissionTotal = ct + (ct*.30) + (ctsp * .05);
	return commissionTotal;
}

float Manager::calcSalary()
{
	salaryTotal = baseSalary + commissionTotal;
	return salaryTotal;
}