#include "Auto_Insurance.h"

float AutoInsurance::calcComission()
{
	commission = (liabilityCov + collisionCov)*0.30;
	return commission;
}
