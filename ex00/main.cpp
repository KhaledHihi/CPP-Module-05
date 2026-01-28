#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Khaled", 2);
        std::cout << a << std::endl;

        a.incrementBureaucrat();
        std::cout << a << std::endl;

        a.incrementBureaucrat();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
