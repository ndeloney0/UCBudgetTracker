#pragma once

#include "funds_base.hpp"
#include <string>
class FundsLoan : public FundsBase 
{
public: 
	FundsLoan(FundsBase *amount, double percent, int days, std::string label) 
	: fund_(amount), interest_percent_(percent), days_before_payment_(days), label_(label) {}
	virtual double GetValue() override
	{
		return fund_->GetValue();
	}
	double GetValueWithInterest()
	{
		double interest_percent = interest_percent_/100;
		double interest_rate_factor = interest_percent / 365;
		double daily_interest_amount = (fund_->GetValue()*interest_rate_factor);
		return daily_interest_amount*days_before_payment_ + fund_->GetValue();
	}
	std::string GetNameOfLoan()
	{
		return label_;
	}
private:
	int days_before_payment_;
	double interest_percent_;
	FundsBase *fund_;
	std::string label_;

};