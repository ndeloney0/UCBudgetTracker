#include "calculate_ucsb.hpp"
#include "../student_account.hpp"
CalculateUcsb::CalculateUcsb(){};
double CalculateUcsb::CalculateBudget(StudentAccount *account)
{
	double budget = CalculateBase::CalculateBudget(account);
	if (this->GetState())
	{
		account->SetTuitionCost(14391);
	}
	else
	{
		account->SetTuitionCost(44145);
	}
	budget -= account->GetTuitionCost();
	if (this->GetBooks())
	{
		budget -= 1260;
	}
	return budget;	
}