#pragma once
class StudentAccount;
class CalculateBase
{
public:
	CalculateBase();

	void SetState(bool instate);
	bool GetState();
	void SetBooks(bool books);
	bool GetBooks();


	/* Pure Virtual */

	virtual double CalculateBudget(StudentAccount *account);

private: 
	bool instate_;
	bool books_;
};