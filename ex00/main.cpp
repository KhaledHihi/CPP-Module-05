#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Khaled" ,150);
		a.decrement_grade();
		std::cout << a << std::endl;
		a.decrement_grade();
	}
	catch (std::exception& e)
    {
        std::cout << "throw: " << e.what() << std::endl;
    }
	return 0;
}
