#include "calculate_ucd.hpp"
#include "../student_account.hpp"
CalculateUcd::CalculateUcd(){};
double CalculateUcd::CalculateBudget(StudentAccount *account)
{
	double budget = CalculateBase::CalculateBudget(account);
	if (this->GetState())
	{
		account->SetTuitionCost(14495);
	}
	else
	{
		account->SetTuitionCost(44249);
	}
	budget -= account->GetTuitionCost();
	if (this->GetBooks())
	{
		budget -= 1159;
	}
	return budget;	
}