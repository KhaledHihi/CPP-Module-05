#pragma once

#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const unsigned int gradeSign;
        const unsigned int gradeExecute;

    public:
        AForm();

        AForm(const std::string &name, const unsigned int &gradeSign, const unsigned int &gradeExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

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
        virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &output, const AForm &other);