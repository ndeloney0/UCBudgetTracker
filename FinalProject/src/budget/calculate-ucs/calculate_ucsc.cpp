#include "calculate_ucsc.hpp"
#include "../student_account.hpp"
CalculateUcsc::CalculateUcsc(){};
double CalculateUcsc::CalculateBudget(StudentAccount *account)
{
	double budget = CalculateBase::CalculateBudget(account);
	if (this->GetState())
	{
		account->SetTuitionCost(13991);
	}
	else
	{
		account->SetTuitionCost(43745);
	}
	budget -= account->GetTuitionCost();
	if (this->GetBooks())
	{
		budget -= 1161;
	}
	return budget;	
}