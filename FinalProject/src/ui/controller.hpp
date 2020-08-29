#pragma once

#include <memory>

#include "model.hpp"
#include "view.hpp"

namespace ui
{
	class ui_controller : public view_delegate
	{
	public:
		explicit ui_controller() noexcept :
			view_(std::make_unique<view>(this, 650.0, 800.0))
		{
			model_ = std::make_unique<model>(static_cast<int>(uc_school::riverside));
		}

		bool run() const
		{	
			view_->init();

			model_->set_school(static_cast<int>(view_->get_school()), view_->in_state());
			model_->set_balance(view_->get_balance());
			
			while (view_->render())
			{
				model_->set_school(static_cast<int>(view_->get_school()), view_->in_state());
				model_->set_balance(view_->get_balance());
			}

			return true;
		}

		virtual void loan_callback(loan loan) override
		{
			model_->add_loan(loan.label, loan.value, loan.percent, loan.days);
		}
		
		virtual void fund_callback(monthly_fund fund) override
		{
			model_->add_fund(fund.label, fund.value, fund.months);
		}

		virtual void loan_remove_callback(loan loan) override
		{
			model_->remove_loan(loan.label);
		}
		
		virtual void fund_remove_callback(monthly_fund fund) override
		{
			model_->remove_fund(fund.label);
		}

		virtual double query_final_balance() override
		{
			return model_->get_final_balance();
		}
		
		virtual double query_loan_owed() override
		{
			return model_->get_loan_dues();
		}

	private:
		
		std::unique_ptr<view> view_;
		std::unique_ptr<model> model_;
	};
}