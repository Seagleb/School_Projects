#include "Life_Insurance.h"


float LifeInsurance::calcComission()
{
	commission = (lifeTermCov*0.20);
	return commission;
}