#pragma once
#include "calculate_base.hpp"
class CalculateUcd : public CalculateBase
{
public:
	CalculateUcd();
	double CalculateBudget(StudentAccount *account);
};