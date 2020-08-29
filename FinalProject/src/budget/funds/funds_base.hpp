#pragma once
class FundsBase
{
public: 
	FundsBase(){value_ = 0;}
	FundsBase(double value) : FundsBase(){value_ = value;}
	virtual double GetValue() {return value_;}

private:
	double value_;
};