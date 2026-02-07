#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void header(const std::string& title)
{
	std::cout << "\n==== " << title << " ====\n";
}

int main()
{
	header("Test 1: Create Forms");
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

	header("Test 2: ShrubberyCreationForm");
	try {
		Bureaucrat signer("Signer", 1);
		ShrubberyCreationForm form("garden");
		std::cout << form << std::endl;

		signer.signForm(form);
		signer.executeForm(form);

		std::cout << form << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	header("Test 3: RobotomyRequestForm Execution");
	try {
		Bureaucrat b("Roboticist", 45);
		RobotomyRequestForm form("Android");
		
		b.signForm(form);
		b.executeForm(form);
		b.executeForm(form);
		b.executeForm(form);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	header("Test 4: PresidentialPardonForm Execution");
	try {
		Bureaucrat b("President", 5);
		PresidentialPardonForm form("Criminal");
		
		b.signForm(form);
		b.executeForm(form);
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
