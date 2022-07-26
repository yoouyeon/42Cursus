/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:46:14 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/26 16:33:40 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// ANCHOR constructor, canonical form
RobotomyRequestForm::RobotomyRequestForm(void) : Form("robotomy request", R_SIGN_GRADE, R_EXEC_GRADE)
{
	std::cout << "[ RobotomyRequestForm Default Constructor called ]" << std::endl;
	_target = "";
	std::cout << "RobotomyRequestForm Form is created " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("robotomy request", R_SIGN_GRADE, R_EXEC_GRADE)
{
	std::cout << "[ RobotomyRequestForm Constructor called ]" << std::endl;
	_target = target;
	std::cout << "RobotomyRequestForm Form is created " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &origin) : Form("robotomy request", origin.getRequiredSignGrade(), origin.getRequiredExecGrade())
{
	std::cout << "[ RobotomyRequestForm Copy Constructor called ]" << std::endl;
	_target = origin.getTarget();
	setSigned(origin.isSigned());
	std::cout << "RobotomyRequestForm is copied " << *this << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is destroyed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &origin)
{
	std::cout << "[ RobotomyRequestForm Copy Assign operator called ]" << std::endl;
	if (this != &origin)
	{
		_target = origin.getTarget();
		setSigned(origin.isSigned());
	}
	std::cout << "RobotomyRequestForm is copied (only Target and sign) " << *this << std::endl;
	return (*this);
}

// ANCHOR accessor
const std::string RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

// ANCHOR others
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static int first_execute;

	if (first_execute == 0)
	{
		first_execute = 1;
		srand(time(NULL));
	}
	if (isSigned() == false)
		throw(Form::NotSignedFormException());
	else if (executor.getGrade() > getRequiredExecGrade())
		throw(Form::GradeTooLowException());
	else
	{
		std::cout << "drrrr... drrrrrrr..." << std::endl;
		if (rand() % 2 == 0)
			std::cout << _target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Fail to robotomize " << _target << std::endl;
	}
}

std::ostream &operator<<(std::ostream &c, const RobotomyRequestForm &f)
{
	c << "[ Form name : " << f.getName() << ", is sigined : ";
	if (f.isSigned() == true)
		c << "true";
	else
		c << "false";
	c << ", required grade : sign(" << f.getRequiredSignGrade() << ") / exec(" << f.getRequiredExecGrade() << ") , target : "<< f.getTarget() << " ]";
	return (c);
}
