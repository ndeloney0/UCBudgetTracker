#include "calculate_ucr.hpp"
#include "../student_account.hpp"
#include <iostream>
CalculateUcr::CalculateUcr(){};
double CalculateUcr::CalculateBudget(StudentAccount *account)
{
	double budget = CalculateBase::CalculateBudget(account);
	if (this->GetState())
	{
		account->SetTuitionCost(13853);
	}
	else
	{
		account->SetTuitionCost(43607);
	}
	budget -= account->GetTuitionCost();
	if (this->GetBooks())
	{
		budget -= 1525;
	}
	return budget;	
}