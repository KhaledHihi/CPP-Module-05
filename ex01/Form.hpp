#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string name;
        bool isSigned;
        const unsigned int gradeSign;
        const unsigned int gradeExecute;

    public:
        Form();

        Form(const std::string &name, const unsigned int &gradeSign, const unsigned int &gradeExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        unsigned int getGradeSign() const;
        unsigned int getGradeExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);
        
        class GradeTooHighException: public std::exception {
            const char *what() const throw();
        };
        class GradeTooLowException: public std::exception {
            const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &output, const Form &other);