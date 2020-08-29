#pragma once
#include "calculate_base.hpp"
class CalculateUcb : public CalculateBase
{
public:
	CalculateUcb();
	double CalculateBudget(StudentAccount *account);
};