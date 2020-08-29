#pragma once

#include <string>

#include "funds_base.hpp"

/*  IMPORTANT READ ME 
	This class determines if the funds will be
	subtracting to or adding from the budget based
	on if the user input a negative number or not.
	The user input will not actually be negative,
	but the number will have to converted to negative
	if the input is considered an expense.
*/

class FundsMonthly : public FundsBase
{
public:
	FundsMonthly(FundsBase *amount, std::string label, int num) 
	: fund_(amount), label_(label), num_months_(num){}
	virtual double GetValue() override
	{
		return fund_->GetValue();
	}
	std::string GetNameOfFunds()
	{
		return label_;
	}
	double GetMonths()
	{
		return num_months_;
	}

private:
	int num_months_;
	FundsBase *fund_;
	std::string label_;
};