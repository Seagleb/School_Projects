#ifndef Home_Insurance_h_
#define Home_Insurance_h_

#include "Insurance.h"
#include <vector>

class HomeInsurance : public Insurance
{
protected:
	int squareft;
	float dwellingCov;
	float contentsCov;
	float liabilityCov;

public:
	HomeInsurance(string n, int sf, float d, float l, float c,int id) { name = n; squareft = sf; dwellingCov = d; liabilityCov = l; contentsCov = c; salesmanID = id; type = "Home"; }
	float calcComission();
};

#endif
