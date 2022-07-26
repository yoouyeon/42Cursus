/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:46:11 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/26 15:50:51 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// ANCHOR constructor, canonical form
PresidentialPardonForm::PresidentialPardonForm(void) : Form("presidential pardon", P_SIGN_GRADE, P_EXEC_GRADE)
{
	std::cout << "[ PresidentialPardonForm Default Constructor called ]" << std::endl;
	_target = "";
	std::cout << "PresidentialPardonForm Form is created " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("presidential pardon", P_SIGN_GRADE, P_EXEC_GRADE)
{
	std::cout << "[ PresidentialPardonForm Constructor called ]" << std::endl;
	_target = target;
	std::cout << "PresidentialPardonForm Form is created " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &origin) : Form("presidential pardon", origin.getRequiredSignGrade(), origin.getRequiredExecGrade())
{
	std::cout << "[ PresidentialPardonForm Copy Constructor called ]" << std::endl;
	_target = origin.getTarget();
	setSigned(origin.isSigned());
	std::cout << "PresidentialPardonForm is copied " << *this << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm " << this->getName() << " is destroyed" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &origin)
{
	std::cout << "[ PresidentialPardonForm Copy Assign operator called ]" << std::endl;
	if (this != &origin)
	{
		_target = origin.getTarget();
		setSigned(origin.isSigned());
	}
	std::cout << "PresidentialPardonForm is copied (only Target and sign) " << *this << std::endl;
	return (*this);
}

// ANCHOR accessor
const std::string PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

// ANCHOR others
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (isSigned() == false)
		throw(Form::NotSignedFormException());
	else if (executor.getGrade() > getRequiredExecGrade())
		throw(Form::GradeTooLowException());
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &c, const PresidentialPardonForm &f)
{
	c << "[ Form name : " << f.getName() << ", is sigined : ";
	if (f.isSigned() == true)
		c << "true";
	else
		c << "false";
	c << ", required grade : sign(" << f.getRequiredSignGrade() << ") / exec(" << f.getRequiredExecGrade() << ") , target : "<< f.getTarget() << " ]";
	return (c);
}
