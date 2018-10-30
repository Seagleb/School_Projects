#ifndef Employee_h
#define Employee_h

#include <iostream>

using namespace std;

class Employee
{
protected:
	string name;
	string type;
	float baseSalary;
	float commission;
	float commissionTotal;
	float salaryTotal;
	int salesMade;
	int id;
	int managerID;

public:

	friend ostream &operator<<(ostream &, Employee &);

	string getName() { return name; }
	string getType() { return type; }
	float getCommision() { return commission; }
	float getBaseSalary() { return baseSalary; }
	float getCommissionTotal() { return commissionTotal; }
	float getSalaryTotal() { return salaryTotal; }
	int getID() { return id; }
	int getSalesMade() { return salesMade; }
	int getManagerID() { return managerID; }
	virtual float calcComission(float , float) = 0;
	virtual float calcSalary() = 0;

	void setCommission(float c) { commission = c; }
	void setManagerID(int i) { managerID = i; }
	void getType(string t) { type = t; }
	void setID(int i) { id = i; }
	void setName(string n) { name = n; }
	void setBaseSalary(float bs) { baseSalary = bs; }
	void setCommissionTotal(float ct) { commissionTotal= ct; }
	void setSalaryTotal(float st) { salaryTotal = st; }
	void setSalesMade(int sm) { salesMade = sm; }
};

#endif