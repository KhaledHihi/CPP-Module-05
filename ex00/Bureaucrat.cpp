#include "Bureaucrat.hpp"
std::string Bureaucrat::getname(){ return name;}

int Bureaucrat::getgrade(){ return grade;}

Bureaucrat::Bureaucrat(): name("unknown"), grade(150){
}

Bureaucrat::Bureaucrat(std::string name, int gradee): name(name){
    if (gradee > 150)
        throw Bureaucrat::GradeTooHighException();
    else if (gradee < 1)
        throw Bureaucrat::GradeTooLowException();
    else
        grade = gradee;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name){
	grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	grade = other.grade;
	return *this;
}
Bureaucrat::~Bureaucrat(){}