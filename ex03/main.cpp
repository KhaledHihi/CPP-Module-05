#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(){
    std::cout << BLUE;
    try {
        Bureaucrat khaled("khaled", 2);
        std::cout << khaled << std::endl;
        
        Intern intern;
        AForm *form = intern.makeForm("ShrubberyCreationForm", "garden");

        form->beSigned(khaled);
        
        std::cout << "========================================================================" << std::endl;
        form->execute(khaled);
        std::cout << "========================================================================" << std::endl;
        
        delete form;
    }
    catch (const std::exception &e){
        std::cout << "========================================================================" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "========================================================================" << std::endl;
    }
}