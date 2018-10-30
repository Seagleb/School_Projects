#include "Home_Insurance.h"

float HomeInsurance::calcComission()
{
	commission = (liabilityCov*0.30)+((dwellingCov+contentsCov)*0.20);
	return commission;
}