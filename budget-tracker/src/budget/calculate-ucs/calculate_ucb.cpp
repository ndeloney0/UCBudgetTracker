#include "calculate_ucb.hpp"
#include "../student_account.hpp"
CalculateUcb::CalculateUcb(){};
double CalculateUcb::CalculateBudget(StudentAccount *account)
{
	double budget = CalculateBase::CalculateBudget(account);
	if (this->GetState())
	{
		account->SetTuitionCost(14253);
	}
	else
	{
		account->SetTuitionCost(44007);
	}
	budget -= account->GetTuitionCost();
	if (this->GetBooks())
	{
		budget -= 1094;
	}
	return budget;	
}