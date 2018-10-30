#ifndef Insurance_h
#define Insurance_h

#include <iostream>

using namespace std;

class Insurance
{
protected:
	string name;
	string type;
	float commission;
	int salesmanID;

public:

	friend ostream &operator<<(ostream &,Insurance &);

	string getName() { return name; }
	string getType() { return type; }
	int getSalesmanID() { return salesmanID; }
	float getCommission() { return commission; }

	void setSalesmanID(int i) { salesmanID = i; }
	void setName(string n) { name = n; }
	void setCommission(float c) { commission = c; }
	void setType(string t) { type = t; }

	virtual float calcComission() = 0;
};

#endif
