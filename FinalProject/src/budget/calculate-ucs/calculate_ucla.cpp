#include "calculate_ucla.hpp"
#include "../student_account.hpp"
CalculateUcla::CalculateUcla(){};
double CalculateUcla::CalculateBudget(StudentAccount *account)
{
	double budget = CalculateBase::CalculateBudget(account);
	if (this->GetState())
	{
		account->SetTuitionCost(13240);
	}
	else
	{
		account->SetTuitionCost(42994);
	}
	budget -= account->GetTuitionCost();
	if (this->GetBooks())
	{
		budget -= 1314;
	}
	return budget;	
}