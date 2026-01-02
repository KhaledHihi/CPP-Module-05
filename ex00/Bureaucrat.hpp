#pragma once

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
        Bureaucrat(std::string name ,int gradee);

        class GradeTooHighException: public std::exception
		{
			const char* what() const _GLIBCXX_NOTHROW;
		};

        class GradeTooLowException: public std::exception
		{
			const char* what() const _GLIBCXX_NOTHROW;
		};

        std::string getname();
		int getgrade();
		void increment_grade();
		void decrement_grade();
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& other);