#pragma once
#include "calculate_base.hpp"
class CalculateUcm : public CalculateBase
{
public:
	CalculateUcm();
	double CalculateBudget(StudentAccount *account);
};