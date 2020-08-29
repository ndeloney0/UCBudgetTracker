#pragma once
#include <vector>
#include <type_traits>

#include "funds/funds_base.hpp"
#include "funds/funds_loan.hpp"
#include "funds/funds_monthly.hpp"

#include "calculate-ucs/calculate_base.hpp"
class CalculateBase;
enum class fund_type 
{
	fund,
	loan,
	monthly
};
class StudentAccount
{
public:
	StudentAccount();
	StudentAccount(CalculateBase *school) : uc_school_(school){};
	void AddFunds(FundsBase *funds);
	void AddFunds(FundsLoan *loan);
	void AddFunds(FundsMonthly *monthly);
	void SetSchool(CalculateBase *school);
	void SetTuitionCost(double cost);
	double GetTuitionCost();
	void SetBalance(double balance);
	double GetBalance();

	template <fund_type Fund>
	auto RemoveFunds(std::string label)
	{
		if constexpr(Fund == fund_type::fund)
			funds_list_.pop_back();
		if constexpr(Fund == fund_type::loan)
		{
			bool found = false;
			int i = 0;
			while (!found)
			{
				if (loan_list_.at(i)->GetNameOfLoan() == label)
				{
					loan_list_.erase(loan_list_.begin()+i);
					found = true;
				}
				i++;
			}
		}
		if constexpr(Fund == fund_type::monthly)
		{
			bool found = false;
			int i = 0;
			while (!found)
			{
				if (monthly_list_.at(i)->GetNameOfFunds() == label)
				{
					monthly_list_.erase(monthly_list_.begin()+i);
					found = true;
				}
				i++;
			}
		}
	}



	template <fund_type Fund>
	auto ListSize()
	{
		if constexpr(Fund == fund_type::fund)
			return funds_list_.size();
		if constexpr(Fund == fund_type::loan)
			return loan_list_.size();
		if constexpr(Fund == fund_type::monthly)
			return monthly_list_.size();		
	}
	template <fund_type Fund>
	auto At(int i)
	{
		if constexpr(Fund == fund_type::fund)
			return funds_list_.at(i);
		if constexpr(Fund == fund_type::loan)
			return loan_list_.at(i);
		if constexpr(Fund == fund_type::monthly)
			return monthly_list_.at(i);
	}


	/* Virtual Functions */
	
	virtual double CalculateBudget();
	virtual void SetState(bool instate);
	virtual void SetBooks(bool books);

protected:
	CalculateBase *uc_school_;

private:
	double balance_;
	double tuition_cost_; 
	std::vector<FundsBase*> funds_list_;

	std::vector<FundsLoan*> loan_list_;
	std::vector<FundsMonthly*> monthly_list_;


};