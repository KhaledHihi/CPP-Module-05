#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 10);
        Bureaucrat jim("Jim", 100);

        Form tax("TaxForm", 50, 25);
        Form secret("SecretForm", 5, 2);

        std::cout << bob << std::endl;
        std::cout << jim << std::endl;
        std::cout << tax << std::endl;
        std::cout << secret << std::endl;

        bob.signForm(tax);
        jim.signForm(tax);
        bob.signForm(secret);

        std::cout << tax << std::endl;
        std::cout << secret << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}