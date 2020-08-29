CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(Dependencies/GLFW/include-mac)
link_directories(Dependencies/GLFW/lib-macos)

ADD_EXECUTABLE(program
	FinalProject/src/imgui/imgui.cpp
	FinalProject/src/imgui/imgui_demo.cpp
	FinalProject/src/imgui/imgui_draw.cpp
	FinalProject/src/imgui/imgui_impl_glfw.cpp
	FinalProject/src/imgui/imgui_impl_opengl3.cpp
	FinalProject/src/imgui/imgui_widgets.cpp
	FinalProject/src/main.cpp
	FinalProject/src/budget/student_account.cpp	
	FinalProject/src/budget/calculate-ucs/calculate_base.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucr.cpp
	FinalProject/src/budget/calculate-ucs/calculate_uci.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucd.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucsc.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucm.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucsb.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucsd.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucla.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucb.cpp
)
ADD_EXECUTABLE(test_program
	tests/unit_tests.cpp
	FinalProject/src/budget/student_account.cpp	
	FinalProject/src/budget/calculate-ucs/calculate_base.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucr.cpp
	FinalProject/src/budget/calculate-ucs/calculate_uci.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucd.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucsc.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucm.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucsb.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucsd.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucla.cpp
	FinalProject/src/budget/calculate-ucs/calculate_ucb.cpp
)


find_package(GLEW REQUIRED)
target_link_libraries(program GLEW::GLEW)
target_link_libraries(program libglfw.3.dylib)
TARGET_LINK_LIBRARIES(test_program gtest)