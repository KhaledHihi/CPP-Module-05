#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknown name"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementBureaucrat()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementBureaucrat()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low!";
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &other)
{
    output << other.getName() << ", bureaucrat grade " << other.getGrade();
    return output;
}
