#include "calculate_base.hpp"
#include "../student_account.hpp"
CalculateBase::CalculateBase(){}
void CalculateBase::SetState(bool instate)
{
	instate_ = instate;
}

bool CalculateBase::GetState()
{
	return instate_;
}
void CalculateBase::SetBooks(bool books)
{
	books_ = books;
}
bool CalculateBase::GetBooks()
{
	return books_;
}


double CalculateBase::CalculateBudget(StudentAccount *account)
{
	double budget = account->GetBalance();
	for (int i = 0; i < account->ListSize<fund_type::loan>(); i++)
	{
		budget += account->At<fund_type::loan>(i)->GetValue();
	}
	for (int i = 0; i < account->ListSize<fund_type::monthly>(); i++)
	{
		budget += account->At<fund_type::monthly>(i)->GetValue()*account->At<fund_type::monthly>(i)->GetMonths();
	}
	return budget;
}
