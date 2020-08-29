#pragma once
#include "calculate_base.hpp"
class CalculateUci : public CalculateBase
{
public:
	CalculateUci();
	double CalculateBudget(StudentAccount *account);
};