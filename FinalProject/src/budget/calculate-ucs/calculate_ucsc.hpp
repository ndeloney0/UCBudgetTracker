#pragma once
#include "calculate_base.hpp"
class CalculateUcsc : public CalculateBase
{
public:
	CalculateUcsc();
	double CalculateBudget(StudentAccount *account);
};