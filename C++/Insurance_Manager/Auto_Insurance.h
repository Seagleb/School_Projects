#ifndef Auto_Insurance_h_
#define Auto_Insurance_h_

#include "Insurance.h"
#include <vector>

class AutoInsurance : public Insurance
{
protected:
	string makemodel;
	int vin;
	float liabilityCov;
	float collisionCov;
public:
	AutoInsurance() { makemodel = ""; vin = 0; liabilityCov = collisionCov = 0; }
	AutoInsurance(string n, string m, int v, float l, float c, int id) { name = n; makemodel = m; vin = v; liabilityCov = l; collisionCov = c; salesmanID = id; type = "Auto"; }
	float calcComission();
};

#endif