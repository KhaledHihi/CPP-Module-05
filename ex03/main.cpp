#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void header(const std::string& title)
{
	std::cout << "\n==== " << title << " ====\n";
}

int main()
{
	header("Test 1: Create Forms Directly");
	try {
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur");
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	header("Test 2: Intern Creates ShrubberyCreationForm");
	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);
		
		AForm* form = intern.makeForm("ShrubberyCreationForm", "garden");
		if (form) {
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	header("Test 3: Intern Creates RobotomyRequestForm");
	try {
		Intern intern;
		Bureaucrat exec("Executor", 45);
		
		AForm* form = intern.makeForm("RobotomyRequestForm", "Marvin");
		if (form) {
			std::cout << *form << std::endl;
			exec.signForm(*form);
			exec.executeForm(*form);
			exec.executeForm(*form);
			exec.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	header("Test 4: Intern Creates PresidentialPardonForm");
	try {
		Intern intern;
		Bureaucrat president("President", 5);
		
		AForm* form = intern.makeForm("PresidentialPardonForm", "Ford");
		if (form) {
			std::cout << *form << std::endl;
			president.signForm(*form);
			president.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

    return 0;
}