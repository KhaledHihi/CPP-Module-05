#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Khaled" ,150);
		a.incrementBureaucrat();
		std::cout << a << std::endl;
	}
	catch (std::exception& e)
    {
        std::cout << "throw: " << e.what() << std::endl;
    }
	return 0;
}
