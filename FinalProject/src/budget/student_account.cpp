#include "student_account.hpp"

StudentAccount::StudentAccount()
{
	balance_ = 0;
	tuition_cost_ = 0;
}

void StudentAccount::SetSchool(CalculateBase *school)
{
	this->uc_school_ = school; 
}

/* Add Funds Functions */

void StudentAccount::AddFunds(FundsBase *funds)
{
	funds_list_.push_back(funds);
}
void StudentAccount::AddFunds(FundsLoan *loan)
{
	this->AddFunds(reinterpret_cast<FundsBase*>(loan));
	loan_list_.push_back(loan);
}
void StudentAccount::AddFunds(FundsMonthly *monthly)
{
	this->AddFunds(reinterpret_cast<FundsBase*>(monthly));
	monthly_list_.push_back(monthly);
}

/* End Add Funds Functions */


void StudentAccount::SetTuitionCost(double cost)
{
	tuition_cost_ = cost;
}
double StudentAccount::GetTuitionCost()
{
	return tuition_cost_;
}
double StudentAccount::CalculateBudget()
{
	return this->uc_school_->CalculateBudget(this);
}
void StudentAccount::SetState(bool instate)
{
	return this->uc_school_->SetState(instate);
}
void StudentAccount::SetBalance(double balance)
{
	this->balance_ = balance;
}
double StudentAccount::GetBalance()
{
	return this->balance_;
}
void StudentAccount::SetBooks(bool books)
{
	return this->uc_school_->SetBooks(books);
}