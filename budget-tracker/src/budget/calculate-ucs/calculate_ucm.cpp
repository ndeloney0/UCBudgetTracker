#include "calculate_ucm.hpp"
#include "../student_account.hpp"
CalculateUcm::CalculateUcm(){};
double CalculateUcm::CalculateBudget(StudentAccount *account)
{
	double budget = CalculateBase::CalculateBudget(account);
	if (this->GetState())
	{
		account->SetTuitionCost(13538);
	}
	else
	{
		account->SetTuitionCost(43292);
	}
	budget -= account->GetTuitionCost();
	if (this->GetBooks())
	{
		budget -= 1047;
	}
	return budget;	
}