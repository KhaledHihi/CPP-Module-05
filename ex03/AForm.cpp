#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(): name("unknown name"), isSigned(false), gradeSign(150), gradeExecute(150){
    std::cout << "Default constructor of AForm is called" << std::endl;
}

AForm::AForm(const std::string &name, const unsigned int &gradeSign, const unsigned int &gradeExecute)
    : name(name), isSigned(false), gradeSign(gradeSign), gradeExecute(gradeExecute){
    if (gradeSign < 1 || gradeExecute < 1){
        throw AForm::GradeTooHighException();
    } else if (gradeSign > 150 || gradeExecute > 150){
        throw AForm::GradeTooLowException();
    }
    
    std::cout << "Parametrised constructor of AForm is called" << std::endl;
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExecute(other.gradeExecute){
    std::cout << "Copy constructor of AForm is called" << std::endl;
}

AForm &AForm::operator=(const AForm &other){
    this->isSigned = other.isSigned;

    std::cout << "Copy assignment operator of AForm is called" << std::endl;
    
    return *this;
}

AForm::~AForm(){
    std::cout << "AForm is destroyed" << std::endl;
}

std::string AForm::getName() const{
    return this->name;
}

bool AForm::getIsSigned() const{
    return this->isSigned;
}

unsigned int AForm::getGradeSign() const {
    return this->gradeSign;
}

unsigned int AForm::getGradeExecute() const {
    return this->gradeExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > getGradeSign()){
        throw AForm::GradeTooLowException();
    }

    this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low!";
}

std::ostream &operator<<(std::ostream &output, const AForm &other){
    return output << other.getName() << ", signed: "
           << (other.getIsSigned() ? "yes" : "no" ) << ", sign grade: " 
           << other.getGradeSign() << ", exec grade: " << other.getGradeExecute();
}
