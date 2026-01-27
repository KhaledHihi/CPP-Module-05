#pragma once

#include <iostream>

class AForm;

class Bureaucrat {
    private:
        const std::string name;
        unsigned int grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, const unsigned int &grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName() const;
        unsigned int getGrade() const;
        
        void incrementBureaucrat();
        void decrementBureaucrat();
        void signForm(const AForm &form);
        void executeForm(AForm const & form);
        
        class GradeTooHighException: public std::exception {
            const char *what() const throw();
        };
        class GradeTooLowException: public std::exception {
            const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &other);
