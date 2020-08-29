#pragma once

#include <array>
#include <memory>

#include "../budget/student_account.hpp"

#include "../budget/calculate-ucs/calculate_base.hpp"
#include "../budget/calculate-ucs/calculate_ucr.hpp"
#include "../budget/calculate-ucs/calculate_ucb.hpp"
#include "../budget/calculate-ucs/calculate_uci.hpp"
#include "../budget/calculate-ucs/calculate_ucsc.hpp"
#include "../budget/calculate-ucs/calculate_ucsd.hpp"
#include "../budget/calculate-ucs/calculate_ucd.hpp"
#include "../budget/calculate-ucs/calculate_ucm.hpp"
#include "../budget/calculate-ucs/calculate_ucsb.hpp"
#include "../budget/calculate-ucs/calculate_ucla.hpp"

namespace ui
{
	class model
	{
	public:
		explicit model(int school) noexcept :
			student_account_(std::make_unique<StudentAccount>())
		{
			student_account_->SetSchool(schools_[school]);
		}

		void set_school(int school, bool in_state) const
		{
			schools_[school]->SetState(in_state);
			student_account_->SetSchool(schools_[school]);
		}

		void set_balance(double balance) const
		{
			student_account_->SetBalance(balance);
		}

		void add_loan(const std::string& label, double amount, double percent, double days) const
		{
			FundsBase* fb_amt = new FundsBase(amount);
			FundsLoan* fb = new FundsLoan(fb_amt, percent, days, label);
			student_account_->AddFunds(fb);
		}

		void remove_loan(const std::string& label) const
		{
			student_account_->RemoveFunds<fund_type::loan>(label);
		}
		
		void add_fund(const std::string& label, double amount, int months) const
		{
			FundsBase* fb_amt = new FundsBase(amount);
			FundsMonthly* fb = new FundsMonthly(fb_amt, label, months);
			student_account_->AddFunds(fb);
		}

		void remove_fund(const std::string& label) const
		{
			student_account_->RemoveFunds<fund_type::monthly>(label);
		}

		double get_final_balance() const
		{
			return student_account_->CalculateBudget();
		}
		
		double get_loan_dues() const
		{	
			double loan_dues = 0.0f;

			for (int i = 0; i < student_account_->ListSize<fund_type::loan>(); ++i)
				loan_dues += student_account_->At<fund_type::loan>(i)->GetValueWithInterest();

			return loan_dues;
		}
		
	private:
		std::array<CalculateBase*, 9> schools_ =
		{ {
			new CalculateUcb(),
			new CalculateUcd(),
			new CalculateUci(),
			new CalculateUcla(),
			new CalculateUcm(),
			new CalculateUcr(),
			new CalculateUcsb(),
			new CalculateUcsc(),
			new CalculateUcsd()
		} };
		
		std::unique_ptr<StudentAccount> student_account_;
	};
}