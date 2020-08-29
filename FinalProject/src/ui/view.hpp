#pragma once

#include <algorithm>

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <string>
#include <array>
#include <vector>
#include <algorithm>

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

namespace ui
{
    struct loan
    {
        std::string label;
        double value;
        double percent;
        int days;

        bool selected;
    };

	struct monthly_fund
	{
        std::string label;
        double value;
        int months;

        bool selected;
	};
	
	enum class uc_school
	{
		berkeley,
		davis,
		irvine,
		los_angeles,
		merced,
		riverside,
		santa_barbara,
		santa_cruz,
		san_diego,
	};

	class view_delegate
	{
	public:
        virtual void loan_callback(loan loan) = 0;
        virtual void fund_callback(monthly_fund fund) = 0;

        virtual void loan_remove_callback(loan loan) = 0;
        virtual void fund_remove_callback(monthly_fund loan) = 0;
		
        virtual double query_final_balance() = 0;
		virtual double query_loan_owed() = 0;
	};
	
	class view
	{
	public:
		explicit view(view_delegate* delegate, float window_height, float window_width) noexcept :
            delegate_(delegate),
			window_height_(window_height),
            window_width_(window_width),
			window_(nullptr),
            starting_balance_(0),
			in_state_(true)
		{}

		double get_balance() const
		{
            return starting_balance_;
		}

		bool in_state() const
		{
            return in_state_;
		}

		uc_school get_school()
		{
			for (auto& school : uc_schools)
			{
                if (school.selected)
                    return school.school;
			}

            return uc_school::riverside;
		}

		bool init()
		{
            // Setup window
            glfwSetErrorCallback(glfw_error_callback);
            if (!glfwInit())
                return false;

            // Decide GL+GLSL versions
#if __APPLE__
    // GL 3.2 + GLSL 150
            const char* glsl_version = "#version 150";
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
            const char* glsl_version = "#version 130";
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
            //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
            //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
            window_ = glfwCreateWindow(650, 400, "UC Student Budget Tracker", NULL, NULL);
            if (window_ == NULL)
                return false;
            glfwMakeContextCurrent(window_);
            glfwSwapInterval(1); // Enable vsync

            // Initialize OpenGL loader
#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
            bool err = gl3wInit() != 0;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
            bool err = glewInit() != GLEW_OK;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
            bool err = gladLoadGL() == 0;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD2)
            bool err = gladLoadGL(glfwGetProcAddress) == 0; // glad2 recommend using the windowing library loader instead of the (optionally) bundled one.
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLBINDING2)
            bool err = false;
            glbinding::Binding::initialize();
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLBINDING3)
            bool err = false;
            glbinding::initialize([](const char* name) { return (glbinding::ProcAddress)glfwGetProcAddress(name); });
#else
            bool err = false; // If you use IMGUI_IMPL_OPENGL_LOADER_CUSTOM, your loader is likely to requires some form of initialization.
#endif
            if (err)
            {
                fprintf(stderr, "Failed to initialize OpenGL loader!\n");
                return false;
            }

            // Setup Dear ImGui context
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO(); (void)io;

            ImGui::GetStyle().WindowRounding = 0.0f;
            ImGui::GetStyle().FrameRounding = 0.0f;

            // Setup Dear ImGui style
            ImGui::StyleColorsDark();

            // Setup Platform/Renderer bindings
            ImGui_ImplGlfw_InitForOpenGL(window_, true);
            ImGui_ImplOpenGL3_Init(glsl_version);

            glfwWindowShouldClose(window_);

            return true;
		}
		
        bool render()
		{
            if (glfwWindowShouldClose(window_))
                return false;
			
            glfwPollEvents();

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            using namespace ImGui;
			
            { // window
                ImGui::SetNextWindowPos(ImVec2(0, 0));
                ImGui::SetNextWindowSize(ImVec2(window_width_, window_height_));

                ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar;

                ImGui::PushStyleColor(ImGuiCol_Border, ImGui::ColorConvertFloat4ToU32({ 0.f, 0.f, 0.f, 0.f }));
                ImGui::Begin("UC Student Budget Tracker", NULL, flags);

                auto header_y_pos = GetCursorPosY();
                auto col_x_1 = 200.0f;
            	
                Text("Select UC");
                //GetStyle().ScrollbarSize = 4;
                //GetStyle().ScrollbarRounding = 0;
                //PushStyleColor(ImGuiCol_ScrollbarBg, ImGuiCol_FrameBg);
                ListBoxHeader("##select uc", { 150, 155 });
                for (auto& school : uc_schools)
                {
                    if (Selectable(school.name.c_str(), &school.selected))
                    {
                        for (auto& other_school : uc_schools)
                            other_school.selected = false;
                        school.selected = true;
                    }
                }
                ListBoxFooter();
                Checkbox("In State", &in_state_);
            	
                Text("");
                Separator();
                Text("");

                std::string final_bal_txt = std::to_string(this->delegate_->query_final_balance());
            	
                auto bal_text = std::string{ "Remaining Balance: " } + final_bal_txt;
                SetCursorPosX(window_height_ / 2 - CalcTextSize(bal_text.c_str()).x / 2);
                Text("Remaining Balance:");
                SameLine();
                TextColored({ 0, 1, 0, 1 }, final_bal_txt.c_str());

                std::string loan_repay_txt = std::to_string(this->delegate_->query_loan_owed());
            	
                std::string txt = std::string{ "Loan Amount To Repay: " } + loan_repay_txt;
                SetCursorPosX(window_height_ / 2 - CalcTextSize(txt.c_str()).x / 2);
                Text(txt.c_str());


                SetCursorPos({ col_x_1 + 80.f, header_y_pos });
                Text("Starting Balance: ");
                SetNextItemWidth(100);

                SameLine();
            	
                //SetCursorPos({ col_x_1, header_y_pos + 20.0f });
            	
                InputDouble("##balance", &starting_balance_, 0, 0, "$%.2f");

                {
                    SetCursorPos({ col_x_1, GetCursorPosY() });
                    ListBoxHeader("loans##loans", { 150, 150 });
                    for (auto& loan : loans_)
                    {
                        if (Selectable(loan.label.c_str(), loan.selected))
                        {
                            loan.selected = true;
                        }
                    }
                    for (int i = 0; i < loans_.size(); ++i)
                    {
                        if (loans_[i].selected)
                        {
                            this->delegate_->loan_remove_callback(loans_[i]);
                            loans_.erase(loans_.begin() + i);
                        }
                    }
                    ListBoxFooter();
                    SetCursorPosX(col_x_1);
                    if (Button("Add Loan", { 100, 20 }))
                        OpenPopup("Loan Entry", 0);
                }

                {
                    SetCursorPos({ col_x_1 * 2, header_y_pos + 22 });
                    ListBoxHeader("funds & costs", { 150, 150 });
                    for (auto& fund : funds_)
                    {
                        if (Selectable(fund.label.c_str(), fund.selected))
                        {
                            fund.selected = true;
                        }
                    }
                    for (int i = 0; i < funds_.size(); ++i)
                    {
                        if (funds_[i].selected)
                        {
                            this->delegate_->fund_remove_callback(funds_[i]);
                            funds_.erase(funds_.begin() + i);
                        }
                    }
                    ListBoxFooter();
                    SetCursorPosX(col_x_1 * 2);
                    if (Button("Add Fund/Expense", { 120, 20 }))
                        OpenPopup("Fund Entry", 0);
                }
            	
                SetNextWindowPos({ 170, 100 });
                SetNextWindowSize({ 300, 140 });
                if (BeginPopupModal("Loan Entry", (bool*)0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar))
                {
                    static char buf[256] = { 0 };
                    InputTextWithHint(" Label", "loan name...", buf, sizeof buf);

                    static int days = 0;
                    if (InputInt(" Days##loan", &days))
                        days = std::clamp(days, 0, 999999);

                    static double value = 0;
                    if (InputDouble(" Value##loan", &value, 0, 0, "$%.2f"))
                        value = std::clamp(value, (double)0.0, (double)999999);

                    static double percent = 0;
                    if (InputDouble(" % Interest##loan", &percent, 0, 0, "%.2f%%"))
                        percent = std::clamp(percent, (double)0.0, (double)999999);

                    Text("");
                	
                    SetCursorPosX(97);
                    if (Button("Submit Loan", { 106, 20 }))
                    {
                    	if (!std::string{buf}.empty() && days > 0 && value > 0)
                        {
                            const loan current_loan = { buf, value, percent, days, false };

                            this->loans_.push_back(current_loan);

                            this->delegate_->loan_callback(current_loan);
                        }

                        memset(buf, 0, sizeof buf);
                        days = 0;
                        value = 0;
                        percent = 0.0f;

                        CloseCurrentPopup();
                    }
                	
                    EndPopup();
                }

                SetNextWindowPos({ 170, 100 });
                SetNextWindowSize({ 300, 140 });
                if (BeginPopupModal("Fund Entry", (bool*)0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar))
                {
                    static char buf[256] = { 0 };
                    InputTextWithHint(" Label##fund", "fund name...", buf, sizeof (ImGuiTextBuffer));

                    static double value = 0;
                    InputDouble(" Value##fund", &value, 0, 0, "$%.2f");

                    static int months = 0;
                    if (InputInt(" Months##fund", &months))
                        months = std::clamp(months, 0, 999999);

                    Text("");

                    SetCursorPosX(97);
                    if (Button("Submit Fund", { 106, 20 }))
                    {
                        if (!std::string{ buf }.empty() && value != 0 && months > 0)
                        {
                            const monthly_fund current_loan = { buf, value, months, false };

                            this->funds_.push_back(current_loan);

                            this->delegate_->fund_callback(current_loan);
                        }

                        memset(buf, 0, sizeof buf);
                        value = 0;
                        months = 0;

                        CloseCurrentPopup();
                    }

                    EndPopup();
                }
                ImGui::PopStyleColor();
                ImGui::End();
            }

            {
                // Rendering
                ImGui::Render();
                int display_w, display_h;
                glfwGetFramebufferSize(window_, &display_w, &display_h);
                glViewport(0, 0, display_w, display_h);
                glClearColor(clear_color_.x, clear_color_.y, clear_color_.z, clear_color_.w);
                glClear(GL_COLOR_BUFFER_BIT);
                ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

                glfwSwapBuffers(window_);
            }

            return true;
		}

        ~view()
        {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();

            glfwDestroyWindow(window_);
            glfwTerminate();
        }
		
	private:
        struct uc
        {
            uc_school school;
            std::string name;
            bool selected;
        };

        view_delegate* delegate_;
		
        float window_height_;
        float window_width_;

        GLFWwindow* window_;

        double starting_balance_;
        bool in_state_;

        std::vector<loan> loans_;
        std::vector<monthly_fund> funds_;

        std::array<uc, 9> uc_schools =
        { {
            {uc_school::berkeley, "UC Berkeley", false},
            {uc_school::davis, "UC Davis", false},
            {uc_school::irvine, "UC Irvine", false},
            {uc_school::los_angeles, "UC Los Angeles", false},
            {uc_school::merced, "UC Merced", false},
            {uc_school::riverside, "UC Riverside", true},
            {uc_school::santa_barbara, "UC Santa Barbara", false},
            {uc_school::santa_cruz, "UC Santa Cruz", false},
            {uc_school::san_diego, "UC San Diego", false}
        } };
		
        ImVec4 clear_color_ = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	};
}
