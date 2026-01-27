#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyForm", 145, 137), target("unknown"){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other){
	target = other.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyForm", 145, 137), target(target){
}

std::string ShrubberyCreationForm::getTarget() const{ return target;}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()){
        throw GradeTooLowException();
    }
    
    if (executor.getGrade() > getGradeExecute()){
        throw GradeTooLowException();
    }

    std::string fileName = getTarget() + "_shrubbery";
    std::ofstream outputFile(fileName.c_str());
    
    if (!outputFile.is_open()){
        throw ErrorCreateFile();
    }
    std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
		outfile <<
		"         v" << std::endl <<
		"        >X<" << std::endl <<
		"         A" << std::endl <<
		"        d$b" << std::endl <<
		"      .d\\$$b." << std::endl <<
		"    .d$i$$\\$$b." << std::endl <<
		"       d$$@b" << std::endl <<
		"      d\\$$$ib" << std::endl <<
		"    .d$$$\\$$$b" << std::endl <<
		"  .d$$@$$$$\\$$ib." << std::endl <<
		"      d$$i$$b" << std::endl <<
		"     d\\$$$$@$b" << std::endl <<
		"  .d$@$$\\$$$$$@b." << std::endl <<
		".d$$$$i$$$\\$$$$$$b." << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl;
		outfile.close();
		std::cout << executor.getName() << " executed ShrubberyCreationForm" << std::endl;
}

const char * ShrubberyCreationForm::ErrorCreateFile::what() const throw() {
    return "Cannot Create output file!";
}

std::ostream &operator<<(std::ostream &output, const ShrubberyCreationForm &other){
    return output << other.getTarget()
        << ", sign grade: " << other.getGradeSign()
        << ", exec grade: " << other.getGradeExecute();
}