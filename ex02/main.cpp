#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat a("Khaled" ,15);
		AForm *d = new PresidentialPardonForm("home");
		std::cout << a << std::endl;
		std::cout << *d << std::endl;
		delete d;
	}
	catch (std::exception& e)
	{
		std::cout << "throw: " << e.what() << std::endl;
	}
	return 0;
}