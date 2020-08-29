![CI](https://github.com/cs100/final-project-blueprint/workflows/CI/badge.svg?branch=master)
# UC Student Budget Tracker
 
 > Authors: [Nicholas Deloney](github.com/ndeloney0), [Adam Kozlowski](github.com/templar)
 
 All backend work done by Nick. All GUI work done by Adam, including wrapping the backend. Cross platform integration was worked on by both authors.
 

## Project Description

   UC Student Budget Tracker is a **Cross Platform for MacOS and Windows** tool , targeted at UC students for keeping track of their budget in a simple, efficient, and intuitive manner. This is an especially important tool as it will allow students to keep track of their income, expenses, scholarships, financial aid, etc. The purpose of this tool is to allow students an easy way to keep track of their finances. Additionally, this tool would be useful for students such as myself trying to budget their money.
   
   The specific strategy patterns being used are strategy, composite, and model-view-controller. Strategy is used for selecting the algorithm to calculate the budget of a student. Composite is used in junction with the different kind of funds the student may have. Model-View-Controller is used for representing the UI, wrapping around the StudentAccount class, and user input/output.
   
   - Strategy: This pattern is used for selecting the algorithm to calculate the budget of a student. Depending on what school the student goes to, if they are paying in state or out of state tuition, and whether they will be paying for books and supplies will allow the program to select a different algorithm when calculating their budget.
   
   - Composite: This pattern is used in junction with the different kinds of funds the student may have. A student may have a monthly expense, and a funds base is used to compose that object into a tree structure to represent a heirarchy. Other fund types include loans.
   
   - Model View Controller: This pattern is used for representing the UI, wrapping the StudentAccount class and user input/output. 
   
   The language is in C++. 
   
   Tools:  
   
   - [Valgrind](https://valgrind.org/) - A suite of tools for debugging and profiling.
  
   - [ImGui](https://github.com/ocornut/imgui) - "Dear ImGui is a bloat-free graphical user interface library for C++. It outputs optimized vertex buffers that you can render anytime in your 3D-pipeline enabled application. It is fast, portable, renderer agnostic and self-contained (no external dependencies)."
          
   - [Git/Github](github.com) - Software development tool providing access control and various functionality.
   
   Libraries: 
   
   - [OpenGL](https://www.opengl.org/) - "OpenGL is a cross-language, cross-platform application programming interface for rendering 2D and 3D vector graphics."
   
   - [GLFW](https://www.glfw.org/) - "GLFW is a lightweight utility library for use with OpenGL. GLFW stands for Graphics Library Framework. It provides programmers with the ability to create and manage windows and OpenGL contexts, as well as handle joystick, keyboard and mouse input."
   
   - [GLEW](http://glew.sourceforge.net/) - "The OpenGL Extension Wrangler Library (GLEW) is a cross-platform open-source C/C++ extension loading library. GLEW provides efficient run-time mechanisms for determining which OpenGL extensions are supported on the target platform. OpenGL core and extension functionality is exposed in a single header file. GLEW has been tested on a variety of operating systems, including Windows, Linux, Mac OS X, FreeBSD, Irix, and Solaris."
   
   User inputs: 
   - Enter Balance
   - Select School
   - Check in or out of state
   - Add a loan with title, interest percent, days until payment, and loan amount
   - Remove a loan
   - Add a monthly fund with title, number of months, and fund amount.
   - Remove a monthly fund.
   
   Outputs:
   - Displays remaining balance.
   - Displays list of loans and funds.
   - Displays accrued interest of loan upon first payment.
   

## Class Diagram

 
Diagram Description: 
 
This application uses both the strategy and composite design patterns. We use the strategy pattern to use different variants of an algorithm (CalculateBudget) within an object (StudentAccount) to switch from one algorithm to another. In other words, depending on what school you go to, the algorithm will calculate your cost of attendance according to your specific school, including what is input by the user. The interface is CalculateBase, variations/concrete strategies is CalculateSchools, and the context is StudentAccount. The composite element is StudentAccount, the leaf is FundsType, and the interface is FundsBase. The composite can add leafs to the container stored within the composite class.
 
![Class Diagram](https://user-images.githubusercontent.com/55167554/90427379-4f09e500-e077-11ea-9514-9c581a083708.png)
 
Diagram Description: 

The applications user interface makes use of the Model-View-Controller (MVC) design pattern. We use this pattern in order to decouple the interation of the user interface code and the code responsible for financial calculations. The controller, ui::ui_controller, instantiates and holds references to both the model and the view class. The model class, ui::model, is a wrapper (or an Adapter) around the StudentAccount(responsible for financial calulations) class which the controller can interface with. The view, ui::view, is a wrapper around the user interface that internally uses imgui library. The view and the model have no knowledge of each other: all interaction between them is done indirectly by the controller. The controller manages the model via it's public member functions. In order to interact with the view, the delegation pattern is additionally used. An abstract base class, ui::view_delegate, defines the member functions that the view will use to notify it's controller of changes, aswell as the functions the view will use to query the controller of information it needs to display. The controller inherits and implements the view_delegate abstract base class, and sets itself as the view's delegate, allowing the two to communicate. 

![Class Diagram](https://user-images.githubusercontent.com/55167554/91611040-33cc8e80-e92f-11ea-8106-c6c9b5d98c5c.png)
 
 
 Sprint 1 (8/10 - 8/20): 
 - Calculate Budget fleshed out. 
 - Ability to add funds and loans. 
 - Label funds and loans appropriately. 
 - Set school. 
 - Set in or out of state tuition. 
 
 Sprint 2 (8/17 - 8/27): 
 - Ability to remove funds and loans. 
 - Ability to select option to pay for books and supplies. 
 - Fully fleshed out GUI added. 
 - Contains all features except books and supplies. 
 - All unit testing completed (CI).
 
 Sprint 3 (8/31 - 9/4):
 - Add the functionality of setting books and supplies to the GUI. 
 - Add an edit menu to edit loans and funds after adding them.
 - Saving student account information after closing program. 
 



 ## Screenshots
 
 **WINDOWS DISPLAY**
 
 ![Initial Display](https://cdn.discordapp.com/attachments/737430044980412529/748846111254642688/unknown.png)
 ![Add Loan Modal](https://cdn.discordapp.com/attachments/737430044980412529/748846403069149274/unknown.png)
 ![Add Fund/Expense Modal](https://cdn.discordapp.com/attachments/737430044980412529/748846986471538698/unknown.png)
 ![Calculation Display](https://cdn.discordapp.com/attachments/737430044980412529/748847161365626930/unknown.png)
 
 **MAC DISPLAY**
 
 ![Example](https://user-images.githubusercontent.com/55167554/91616049-c40fd100-e939-11ea-800b-6440da69411d.png)
 
 ## Installation/Usage
 
 **Windows Installation/Usage:**
 
 
 To compile from scratch:
 - Download source files from latest release.
 - Unzip binaries.zip
 - The project structure is designed to be compiled with Visual Studio/MSBuild.
 - You must have the Dependencies/ folder added under project settings in additional includes, and you must have the GLFW and GLEW library .lib file directories added under additional linker directories. 
 - Your compiler must support C++17.
 
 To use:
  - Download binaries from latest release.
  - Unzip binaries.zip
  - Navigate to the windows folder. 
  - Run the executable.
  
  **Mac Installation/Usage:**
  
  Note: App has not been approved for MacOS platform. App must be compiled directly and ran by the user in order to run.
  
  To compile and use:
  
  For compiling and using on a mac, you will need to have homebrew, glew, cmake, and xcode command line tools installed.
  If you have homebrew, glew, cmake, and xcode installed, you can skip the steps asking you to install those frameworks.
  Additionally, you will need to allow unidentified developer apps to run on your mac.
  Steps:
   - Download source files from latest release. 
   - Open up terminal
   - Installing xcode command line tools:
     - Copy and paste this command into terminal and press enter: 
       > xcode-select --install
   - Installing homebrew:
     - Copy and paste this command into terminal and press enter:
       > ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
   - Installing cmake:
     - Copy and paste this command into terminal and press enter:
       > brew install cmake
   - Installing glew:
     - Copy and paste this command into terminal and press enter:
       > brew install glew
   - Allowing unidentified developer apps to run on your mac:
     - Copy and paste this command into terminal and press enter:
       > sudo spctl --master-disable
     - You can re-enable this security after exiting the program by typing this command:
       > sudo spctl --master-enable
   - Finally, to run the program navigate to the project folder within terminal. 
     - This should look something like the following
       > nick:final-project-blueprint nickdeloney$
     - Copy and paste this command into terminal and press enter:
       > cmake .
       > make
       > ./program
    - And that's it! Your program should have started running! Congratulations!
 
 

 
 ## Testing
 Testing was integrated with CI and google test unit testing. A build passing badge is at the top of this page. The testing under github workflow actions was done using the latest macos release.
