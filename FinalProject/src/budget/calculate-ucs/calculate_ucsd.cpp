#include "calculate_ucsd.hpp"
#include "../student_account.hpp"
CalculateUcsd::CalculateUcsd(){};
double CalculateUcsd::CalculateBudget(StudentAccount *account)
{
	double budget = CalculateBase::CalculateBudget(account);
	if (this->GetState())
	{
		account->SetTuitionCost(14415);
	}
	else
	{
		account->SetTuitionCost(44169);
	}
	budget -= account->GetTuitionCost();
	if (this->GetBooks())
	{
		budget -= 1125;
	}
	return budget;	
}