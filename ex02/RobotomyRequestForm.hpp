#pragma once

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm: public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		RobotomyRequestForm(std::string target);
		std::string getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};