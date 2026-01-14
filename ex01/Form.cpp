#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("unknown name"), isSigned(false), gradeSign(150), gradeExecute(150){
    std::cout << "Default constructor of Form is called" << std::endl;
}
