#pragma once
#include "calculate_base.hpp"
class CalculateUcsd : public CalculateBase
{
public:
	CalculateUcsd();
	double CalculateBudget(StudentAccount *account);
};