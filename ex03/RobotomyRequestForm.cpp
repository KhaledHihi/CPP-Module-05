#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("unknown"){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other){
	target = other.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	this->target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target){}

std::string RobotomyRequestForm::getTarget() const{ return target;}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()){
        throw GradeTooLowException();
    }
    
    if (executor.getGrade() > getGradeExecute()){
        throw GradeTooLowException();
    }

    std::cout << "*drilling noises*" << std::endl;

    if (rand() % 2 == 0){
        std::cout << "Robotomy failed on " + getTarget() << std::endl;
    } else {
        std::cout << getTarget() + " has been robotomized successfully!" << std::endl;
    }
}

std::ostream &operator<<(std::ostream &output, const RobotomyRequestForm &other){
    return output << other.getTarget()
        << ", sign grade: " << other.getGradeSign()
        << ", exec grade: " << other.getGradeExecute();
}