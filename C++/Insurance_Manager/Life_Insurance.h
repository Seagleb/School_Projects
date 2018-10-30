#ifndef Life_Insurance_h_
#define Life_Insurance_h_

#include "Insurance.h"
#include <vector>

class LifeInsurance : public Insurance
{
protected:
	int age;
	string dependent;
	float lifeTermCov;

public:
	LifeInsurance(string n, string dn, int a, float lt, int id) { name = n; dependent = dn; age = a; lifeTermCov = lt; salesmanID = id; type = "life"; }
	float calcComission();
};

#endif
