#pragma once

#include <iostream>

class Bureaucrat {
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, const int &grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        
        void incrementBureaucrat();
        void decrementBureaucrat();

        class GradeTooHighException: public std::exception {
            const char *what() const throw();
        };
        class GradeTooLowException: public std::exception {
            const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &other);

