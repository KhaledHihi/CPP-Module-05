#include "Bureaucrat.hpp"
#include "Form.hpp"


Bureaucrat::Bureaucrat(): name("unknown name"), grade(150){
    std::cout << "Default constructor of Bureaucrat is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int &grade): name(name){
    if (grade < 1){
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150){
        throw Bureaucrat::GradeTooLowException();
    } else {
        this->grade = grade;
    }
    
    std::cout << "Parametrised constructor of Bureaucrat is called" << std::endl;
}

// * Copy constructor with initializer list
Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name), grade(other.grade){
    std::cout << "Copy constructor of Bureaucrat is called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    this->grade = other.grade;

    std::cout << "Copy assignment operator of Bureaucrat is called" << std::endl;
    
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat is destroyed" << std::endl;
}

std::string Bureaucrat::getName() const{
    return this->name;
}
unsigned int Bureaucrat::getGrade() const{
    return this->grade;
}

void Bureaucrat::incrementBureaucrat(){
    if (this->grade <= 1){
        throw Bureaucrat::GradeTooHighException();
    }

    this->grade--;
}

void Bureaucrat::decrementBureaucrat(){
    if (this->grade >= 150){
        throw Bureaucrat::GradeTooLowException();
    }

    this->grade++;
}

void Bureaucrat::signForm(const Form &form){
    if (form.getIsSigned()){
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } else {
        std::cout << getName() << " couldn’t sign " << form.getName() << " because " << "The Grade of Bureaucrat is Lower" << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low!";
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &other){
    return output << other.getName() << ", bureaucrat grade " << other.getGrade();
}
