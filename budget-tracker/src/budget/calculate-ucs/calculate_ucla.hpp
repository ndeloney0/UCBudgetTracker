#pragma once
#include "calculate_base.hpp"
class CalculateUcla : public CalculateBase
{
public:
	CalculateUcla();
	double CalculateBudget(StudentAccount *account);
};