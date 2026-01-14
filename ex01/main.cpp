#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Khaled" ,150);
		for (size_t i = 0; i < 149; i++)
		{
			std::cout << a << std::endl;
			a.decrement_grade();
		}
		a.increment_grade();
		std::cout << a << std::endl;

	}
	catch (std::exception& e)
    {
        std::cout << "throw: " << e.what() << std::endl;
    }
	return 0;
}
