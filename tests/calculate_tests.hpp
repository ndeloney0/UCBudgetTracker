#pragma once

#include "../budget-tracker/src/budget/calculate-ucs/calculate_base.hpp"
#include "../budget-tracker/src/budget/calculate-ucs/calculate_ucr.hpp"
#include "../budget-tracker/src/budget/calculate-ucs/calculate_ucb.hpp"
#include "../budget-tracker/src/budget/calculate-ucs/calculate_uci.hpp"
#include "../budget-tracker/src/budget/calculate-ucs/calculate_ucsc.hpp"
#include "../budget-tracker/src/budget/calculate-ucs/calculate_ucsd.hpp"
#include "../budget-tracker/src/budget/calculate-ucs/calculate_ucd.hpp"
#include "../budget-tracker/src/budget/calculate-ucs/calculate_ucm.hpp"
#include "../budget-tracker/src/budget/calculate-ucs/calculate_ucsb.hpp"
#include "../budget-tracker/src/budget/calculate-ucs/calculate_ucla.hpp"


#include "../budget-tracker/src/budget/student_account.hpp"
#include "../budget-tracker/src/budget/funds/funds_base.hpp"
#include "../budget-tracker/src/budget/funds/funds_loan.hpp"
#include "../budget-tracker/src/budget/funds/funds_monthly.hpp"
#include "gtest/gtest.h"


/* Testing the CaclulateBudget Function for each UC */

TEST(CalculateBudgetTest, TestUcr)
{
	StudentAccount *test_account1 = new StudentAccount();
	test_account1->SetSchool(new CalculateUcr());
	test_account1->SetBooks(false);
	test_account1->SetState(true);
	EXPECT_EQ(test_account1->CalculateBudget(), -13853);
	test_account1->SetState(false);
	EXPECT_EQ(test_account1->CalculateBudget(), -43607);
	test_account1->SetBooks(true);
	EXPECT_EQ(test_account1->CalculateBudget(), -45132);
}
TEST(CalculateBudgetTest, TestUcb)
{
	StudentAccount *test_account1 = new StudentAccount();
	test_account1->SetSchool(new CalculateUcb());
	test_account1->SetBooks(false);
	test_account1->SetState(true);
	EXPECT_EQ(test_account1->CalculateBudget(), -14253);
	test_account1->SetState(false);
	EXPECT_EQ(test_account1->CalculateBudget(), -44007);
	test_account1->SetBooks(true);
	EXPECT_EQ(test_account1->CalculateBudget(), -45101);
}
TEST(CalculateBudgetTest, TestUcd)
{
	StudentAccount *test_account = new StudentAccount();
	test_account->SetSchool(new CalculateUcd());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -14495);
	test_account->SetState(false);
	EXPECT_EQ(test_account->CalculateBudget(), -44249);
	test_account->SetBooks(true);
	EXPECT_EQ(test_account->CalculateBudget(), -45408);
}
TEST(CalculateBudgetTest, TestUci)
{
	StudentAccount *test_account = new StudentAccount();
	test_account->SetSchool(new CalculateUci());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -13727);
	test_account->SetState(false);
	EXPECT_EQ(test_account->CalculateBudget(), -43841);
	test_account->SetBooks(true);
	EXPECT_EQ(test_account->CalculateBudget(), -45202);
}
TEST(CalculateBudgetTest, TestUcla)
{
	StudentAccount *test_account = new StudentAccount();
	test_account->SetSchool(new CalculateUcla());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -13240);
	test_account->SetState(false);
	EXPECT_EQ(test_account->CalculateBudget(), -42994);
	test_account->SetBooks(true);
	EXPECT_EQ(test_account->CalculateBudget(), -44308);
}
TEST(CalculateBudgetTest, TestUcm)
{
	StudentAccount *test_account = new StudentAccount();
	test_account->SetSchool(new CalculateUcm());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -13538);
	test_account->SetState(false);
	EXPECT_EQ(test_account->CalculateBudget(), -43292);
	test_account->SetBooks(true);
	EXPECT_EQ(test_account->CalculateBudget(), -44339);
}
TEST(CalculateBudgetTest, TestUcsb)
{
	StudentAccount *test_account = new StudentAccount();
	test_account->SetSchool(new CalculateUcsb());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -14391);
	test_account->SetState(false);
	EXPECT_EQ(test_account->CalculateBudget(), -44145);
	test_account->SetBooks(true);
	EXPECT_EQ(test_account->CalculateBudget(), -45405);
}
TEST(CalculateBudgetTest, TestUcsc)
{
	StudentAccount *test_account = new StudentAccount();
	test_account->SetSchool(new CalculateUcsc());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -13991);
	test_account->SetState(false);
	EXPECT_EQ(test_account->CalculateBudget(), -43745);
	test_account->SetBooks(true);
	EXPECT_EQ(test_account->CalculateBudget(), -44906);
}
TEST(CalculateBudgetTest, TestUcsd)
{
	StudentAccount *test_account = new StudentAccount();
	test_account->SetSchool(new CalculateUcsd());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -14415);
	test_account->SetState(false);
	EXPECT_EQ(test_account->CalculateBudget(), -44169);
	test_account->SetBooks(true);
	EXPECT_EQ(test_account->CalculateBudget(), -45294);
}


/* Testing Funds with each type of UC */

TEST(FundsTest, TestUcb)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *rent_amt = new FundsBase(-1200);
	FundsBase *shop_amt = new FundsBase(-200);
	FundsBase *job_amt = new FundsBase(1600);
	FundsMonthly *rent = new FundsMonthly(rent_amt, "rent", 10);
	FundsMonthly *groceries = new FundsMonthly(shop_amt, "groceries", 10);
	FundsMonthly *job = new FundsMonthly(job_amt, "job", 10);
	test_account->SetSchool(new CalculateUcb());
	test_account->SetBooks(false);
	test_account->AddFunds(rent);
	test_account->AddFunds(groceries);
	test_account->AddFunds(job);
	EXPECT_EQ(test_account->CalculateBudget(), -42007);
	test_account->RemoveFunds<fund_type::monthly>("groceries");
	EXPECT_EQ(test_account->CalculateBudget(), -40007);
}
TEST(FundsTest, TestUcd)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *rent_amt = new FundsBase(-1200);
	FundsBase *shop_amt = new FundsBase(-200);
	FundsBase *job_amt = new FundsBase(1600);
	FundsMonthly *rent = new FundsMonthly(rent_amt, "rent", 10);
	FundsMonthly *groceries = new FundsMonthly(shop_amt, "groceries", 10);
	FundsMonthly *job = new FundsMonthly(job_amt, "job", 10);
	test_account->SetSchool(new CalculateUcd());
	test_account->AddFunds(rent);
	test_account->AddFunds(groceries);
	test_account->AddFunds(job);
	EXPECT_EQ(test_account->CalculateBudget(), -42249);
	test_account->RemoveFunds<fund_type::monthly>("groceries");
	EXPECT_EQ(test_account->CalculateBudget(), -40249);
}
TEST(FundsTest, TestUci)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *rent_amt = new FundsBase(-1200);
	FundsBase *shop_amt = new FundsBase(-200);
	FundsBase *job_amt = new FundsBase(1600);
	FundsMonthly *rent = new FundsMonthly(rent_amt, "rent", 10);
	FundsMonthly *groceries = new FundsMonthly(shop_amt, "groceries", 10);
	FundsMonthly *job = new FundsMonthly(job_amt, "job", 10);
	test_account->SetSchool(new CalculateUci());
	test_account->AddFunds(rent);
	test_account->AddFunds(groceries);
	test_account->AddFunds(job);
	EXPECT_EQ(test_account->CalculateBudget(), -41841);
	test_account->RemoveFunds<fund_type::monthly>("groceries");
	EXPECT_EQ(test_account->CalculateBudget(), -39841);
}
TEST(FundsTest, TestUcla)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *rent_amt = new FundsBase(-1200);
	FundsBase *shop_amt = new FundsBase(-200);
	FundsBase *job_amt = new FundsBase(1600);
	FundsMonthly *rent = new FundsMonthly(rent_amt, "rent", 10);
	FundsMonthly *groceries = new FundsMonthly(shop_amt, "groceries", 10);
	FundsMonthly *job = new FundsMonthly(job_amt, "job", 10);
	test_account->SetSchool(new CalculateUcla());
	test_account->AddFunds(rent);
	test_account->AddFunds(groceries);
	test_account->AddFunds(job);
	EXPECT_EQ(test_account->CalculateBudget(), -40994);
	test_account->RemoveFunds<fund_type::monthly>("groceries");
	EXPECT_EQ(test_account->CalculateBudget(), -38994);
}
TEST(FundsTest, TestUcm)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *rent_amt = new FundsBase(-1200);
	FundsBase *shop_amt = new FundsBase(-200);
	FundsBase *job_amt = new FundsBase(1600);
	FundsMonthly *rent = new FundsMonthly(rent_amt, "rent", 10);
	FundsMonthly *groceries = new FundsMonthly(shop_amt, "groceries", 10);
	FundsMonthly *job = new FundsMonthly(job_amt, "job", 10);
	test_account->SetSchool(new CalculateUcm());
	test_account->AddFunds(rent);
	test_account->AddFunds(groceries);
	test_account->AddFunds(job);
	EXPECT_EQ(test_account->CalculateBudget(), -41292);
	test_account->RemoveFunds<fund_type::monthly>("groceries");
	EXPECT_EQ(test_account->CalculateBudget(), -39292);
}
TEST(FundsTest, TestUcr)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *rent_amt = new FundsBase(-1200);
	FundsBase *shop_amt = new FundsBase(-200);
	FundsBase *job_amt = new FundsBase(1600);
	FundsMonthly *rent = new FundsMonthly(rent_amt, "rent", 10);
	FundsMonthly *groceries = new FundsMonthly(shop_amt, "groceries", 10);
	FundsMonthly *job = new FundsMonthly(job_amt, "job", 10);
	test_account->SetSchool(new CalculateUcr());
	test_account->AddFunds(rent);
	test_account->AddFunds(groceries);
	test_account->AddFunds(job);
	EXPECT_EQ(test_account->CalculateBudget(), -41607);
	test_account->RemoveFunds<fund_type::monthly>("groceries");
	EXPECT_EQ(test_account->CalculateBudget(), -39607);
}
TEST(FundsTest, TestUcsb)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *rent_amt = new FundsBase(-1200);
	FundsBase *shop_amt = new FundsBase(-200);
	FundsBase *job_amt = new FundsBase(1600);
	FundsMonthly *rent = new FundsMonthly(rent_amt, "rent", 10);
	FundsMonthly *groceries = new FundsMonthly(shop_amt, "groceries", 10);
	FundsMonthly *job = new FundsMonthly(job_amt, "job", 10);
	test_account->SetSchool(new CalculateUcsb());
	test_account->AddFunds(rent);
	test_account->AddFunds(groceries);
	test_account->AddFunds(job);
	EXPECT_EQ(test_account->CalculateBudget(), -42145);
	test_account->RemoveFunds<fund_type::monthly>("groceries");
	EXPECT_EQ(test_account->CalculateBudget(), -40145);
}
TEST(FundsTest, TestUcsc)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *rent_amt = new FundsBase(-1200);
	FundsBase *shop_amt = new FundsBase(-200);
	FundsBase *job_amt = new FundsBase(1600);
	FundsMonthly *rent = new FundsMonthly(rent_amt, "rent", 10);
	FundsMonthly *groceries = new FundsMonthly(shop_amt, "groceries", 10);
	FundsMonthly *job = new FundsMonthly(job_amt, "job", 10);
	test_account->SetSchool(new CalculateUcsc());
	test_account->AddFunds(rent);
	test_account->AddFunds(groceries);
	test_account->AddFunds(job);
	EXPECT_EQ(test_account->CalculateBudget(), -41745);
	test_account->RemoveFunds<fund_type::monthly>("groceries");
	EXPECT_EQ(test_account->CalculateBudget(), -39745);
}
TEST(FundsTest, TestUcsd)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *rent_amt = new FundsBase(-1200);
	FundsBase *shop_amt = new FundsBase(-200);
	FundsBase *job_amt = new FundsBase(1600);
	FundsMonthly *rent = new FundsMonthly(rent_amt, "rent", 10);
	FundsMonthly *groceries = new FundsMonthly(shop_amt, "groceries", 10);
	FundsMonthly *job = new FundsMonthly(job_amt, "job", 10);
	test_account->SetSchool(new CalculateUcsd());
	test_account->AddFunds(rent);
	test_account->AddFunds(groceries);
	test_account->AddFunds(job);
	EXPECT_EQ(test_account->CalculateBudget(), -42169);
	test_account->RemoveFunds<fund_type::monthly>("groceries");
	EXPECT_EQ(test_account->CalculateBudget(), -40169);
}

/* Testing in state vs out of state */

TEST(TestState, TestUcs)
{
	StudentAccount *test_account = new StudentAccount();
	test_account->SetSchool(new CalculateUcb());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -14253);
	test_account->SetState(false); 
	EXPECT_EQ(test_account->CalculateBudget(), -44007);

	test_account->SetSchool(new CalculateUcd());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -14495);
	test_account->SetState(false); 
	EXPECT_EQ(test_account->CalculateBudget(), -44249);

	test_account->SetSchool(new CalculateUci());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -13727);
	test_account->SetState(false); 
	EXPECT_EQ(test_account->CalculateBudget(), -43841);

	test_account->SetSchool(new CalculateUcla());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -13240);
	test_account->SetState(false); 
	EXPECT_EQ(test_account->CalculateBudget(), -42994);

	test_account->SetSchool(new CalculateUcm());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -13538);
	test_account->SetState(false); 
	EXPECT_EQ(test_account->CalculateBudget(), -43292);

	test_account->SetSchool(new CalculateUcr());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -13853);
	test_account->SetState(false); 
	EXPECT_EQ(test_account->CalculateBudget(), -43607);

	test_account->SetSchool(new CalculateUcsb());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -14391);
	test_account->SetState(false); 
	EXPECT_EQ(test_account->CalculateBudget(), -44145);

	test_account->SetSchool(new CalculateUcsc());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -13991);
	test_account->SetState(false); 
	EXPECT_EQ(test_account->CalculateBudget(), -43745);

	test_account->SetSchool(new CalculateUcsd());
	test_account->SetBooks(false);
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -14415);
	test_account->SetState(false); 
	EXPECT_EQ(test_account->CalculateBudget(), -44169);

}

/* Testing for loans */

TEST(TestLoans, TestLoanAffectBudget)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *loan_amt = new FundsBase(1000);
	FundsLoan *loan = new FundsLoan(loan_amt, 5, 100, "Federal Loan");
	test_account->AddFunds(loan);
	test_account->SetSchool(new CalculateUcb());
	test_account->SetState(true);
	EXPECT_EQ(test_account->CalculateBudget(), -13253);
}
TEST(TestLoans, TestRemoveLoan)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *loan_amt = new FundsBase(1000);
	FundsLoan *loan = new FundsLoan(loan_amt, 5, 100, "Federal Loan");
	test_account->AddFunds(loan);
	test_account->SetSchool(new CalculateUcb());
	test_account->SetState(true);
	test_account->RemoveFunds<fund_type::loan>("Federal Loan");
	EXPECT_EQ(test_account->CalculateBudget(), -14253);
}
TEST(TestLoans, TestGetValueWithInterestLoans)
{
	StudentAccount *test_account = new StudentAccount();
	FundsBase *loan_amt = new FundsBase(1000);
	FundsLoan *loan = new FundsLoan(loan_amt, 5, 100, "Federal Loan");
	test_account->AddFunds(loan);
	EXPECT_NEAR(loan->GetValueWithInterest(), 1013.7, 1);
}

/* Testing for books and supplies */

TEST(TestBooks, TestUsesBooks)
{
	StudentAccount *test_account = new StudentAccount();
	test_account->SetSchool(new CalculateUcb());
	test_account->SetState(true);
	test_account->SetBooks(true);
	EXPECT_EQ(test_account->CalculateBudget(), -15347);
}
TEST(TestBooks, TestDoesNotUseBooks)
{
	StudentAccount *test_account = new StudentAccount();
	test_account->SetSchool(new CalculateUcb());
	test_account->SetState(true);
	test_account->SetBooks(false);
	EXPECT_EQ(test_account->CalculateBudget(), -14253);
}

/* Testing Combination of Funds, Loans, Adding, Removing, Books,
   In state, out of state, different UCs */

TEST(TestCombo, TestAll)
{
	StudentAccount *test_account = new StudentAccount();
	test_account->SetSchool(new CalculateUcb());
	test_account->SetState(true);
	FundsBase *monthly_amt = new FundsBase(1000);
	FundsBase *loan_amt = new FundsBase(5000);
	FundsMonthly *monthly = new FundsMonthly(loan_amt, "job", 10);
	FundsLoan *loan = new FundsLoan(loan_amt, 5, 365, "School loan");
	test_account->AddFunds(monthly);
	test_account->AddFunds(loan);
	test_account->SetBooks(true);
	EXPECT_EQ(test_account->CalculateBudget(), 39653);
}




