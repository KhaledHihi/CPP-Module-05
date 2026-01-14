#include "Bureaucrat.hpp"

std::string Bureaucrat::getname(){ return name;}

int Bureaucrat::getgrade(){ return grade;}

Bureaucrat::Bureaucrat(): name("unknown"), grade(150){
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade Too Low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade Too High";
}

void Bureaucrat::increment_grade(){
    if (grade <= 1){
        throw Bureaucrat::GradeTooHighException();
    }

    grade--;
}

void Bureaucrat::decrement_grade(){
    if (grade >= 150){
        throw Bureaucrat::GradeTooLowException();
    }

    grade++;
}

Bureaucrat::Bureaucrat(std::string name, int gradee): name(name){
    if (gradee < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (gradee > 150)
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

std::ostream& operator<<(std::ostream& os, Bureaucrat& other){
	os << other.getname() << " , bureaucrat grade " << other.getgrade();
	return os;
}

Bureaucrat::~Bureaucrat(){}