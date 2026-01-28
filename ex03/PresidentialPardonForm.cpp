#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("unknown"){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other){
	target = other.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target){}

std::string PresidentialPardonForm::getTarget() const{ return target;}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if (!getIsSigned()){
        throw GradeTooLowException();
    }
	if(executor.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &output, const PresidentialPardonForm &other){
    return output << other.getTarget()
        << ", sign grade: " << other.getGradeSign()
        << ", exec grade: " << other.getGradeExecute();
}