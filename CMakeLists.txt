CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(Dependencies/GLFW/include-mac)
link_directories(Dependencies/GLFW/lib-macos)

ADD_EXECUTABLE(program
	budget-tracker/src/imgui/imgui.cpp
	budget-tracker/src/imgui/imgui_demo.cpp
	budget-tracker/src/imgui/imgui_draw.cpp
	budget-tracker/src/imgui/imgui_impl_glfw.cpp
	budget-tracker/src/imgui/imgui_impl_opengl3.cpp
	budget-tracker/src/imgui/imgui_widgets.cpp
	budget-tracker/src/main.cpp
	budget-tracker/src/budget/student_account.cpp	
	budget-tracker/src/budget/calculate-ucs/calculate_base.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucr.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_uci.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucd.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucsc.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucm.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucsb.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucsd.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucla.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucb.cpp
)
ADD_EXECUTABLE(test_program
	tests/unit_tests.cpp
	budget-tracker/src/budget/student_account.cpp	
	budget-tracker/src/budget/calculate-ucs/calculate_base.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucr.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_uci.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucd.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucsc.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucm.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucsb.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucsd.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucla.cpp
	budget-tracker/src/budget/calculate-ucs/calculate_ucb.cpp
)


find_package(GLEW REQUIRED)
target_link_libraries(program GLEW::GLEW)
target_link_libraries(program libglfw.3.dylib)
TARGET_LINK_LIBRARIES(test_program gtest)