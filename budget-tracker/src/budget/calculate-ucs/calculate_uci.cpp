#include "calculate_uci.hpp"
#include "../student_account.hpp"
CalculateUci::CalculateUci(){};
double CalculateUci::CalculateBudget(StudentAccount *account)
{
	double budget = CalculateBase::CalculateBudget(account);
	if (this->GetState())
	{
		account->SetTuitionCost(13727);
	}
	else
	{
		account->SetTuitionCost(43841);
	}
	budget -= account->GetTuitionCost();
	if (this->GetBooks())
	{
		budget -= 1361;
	}

	return budget;	
}