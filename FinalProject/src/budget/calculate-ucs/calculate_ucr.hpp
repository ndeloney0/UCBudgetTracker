#pragma once
#include "calculate_base.hpp"
class CalculateUcr : public CalculateBase
{
public:
	CalculateUcr();
	double CalculateBudget(StudentAccount *account);
};