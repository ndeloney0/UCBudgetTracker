#pragma once
#include "calculate_base.hpp"
class CalculateUcsb : public CalculateBase
{
public:
	CalculateUcsb();
	double CalculateBudget(StudentAccount *account);
};