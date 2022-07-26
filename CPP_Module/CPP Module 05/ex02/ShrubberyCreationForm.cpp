/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:46:17 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/26 13:54:10 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// ANCHOR constructor, canonical form
ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("shrubbery creation", S_SIGN_GRADE, S_EXEC_GRADE)
{
	std::cout << "[ ShrubberyCreationForm Default Constructor called ]" << std::endl;
	_target = "";
	std::cout << "ShrubberyCreationForm Form is created " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shrubbery creation", S_SIGN_GRADE, S_EXEC_GRADE)
{
	std::cout << "[ ShrubberyCreationForm Constructor called ]" << std::endl;
	_target = target;
	std::cout << "ShrubberyCreationForm Form is created " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &origin) : Form("shrubbery creation", origin.getRequiredSignGrade(), origin.getRequiredExecGrade())
{
	std::cout << "[ ShrubberyCreationForm Copy Constructor called ]" << std::endl;
	_target = origin.getTarget();
	setSigned(origin.isSigned());
	std::cout << "ShrubberyCreationForm is copied " << *this << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " is destroyed" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &origin)
{
	std::cout << "[ ShrubberyCreationForm Copy Assign operator called ]" << std::endl;
	if (this != &origin)
	{
		_target = origin.getTarget();
		setSigned(origin.isSigned());
	}
	std::cout << "ShrubberyCreationForm is copied (only Target and sign) " << *this << std::endl;
	return (*this);
}

// ANCHOR accessor
const std::string ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

// ANCHOR others
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (isSigned() == false)
		throw(Form::NotSignedFormException());
	else if (executor.getGrade() > getRequiredExecGrade())
		throw(Form::GradeTooLowException());
	else
	{
		std::string filename = _target + "_shrubbery";
		std::ofstream out(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
		if (!out.good())
			throw(Form::ExecFailException());
		else
		{
			out << "       _-_\n";
			out << "    /~~   ~~\\\n";
			out << " /~~         ~~\\\n";
			out << "{               }\n";
			out << " \\  _-     -_  /\n";
			out << "   ~  \\\\ //  ~\n";
			out << "_- -   | | _- _\n";
			out << "  _ -  | |   -_\n";
			out << "      // \\\\\n";
			out.close();
		}
	}
}

std::ostream &operator<<(std::ostream &c, const ShrubberyCreationForm &f)
{
	c << "[ Form name : " << f.getName() << ", is sigined : ";
	if (f.isSigned() == true)
		c << "true";
	else
		c << "false";
	c << ", required grade : sign(" << f.getRequiredSignGrade() << ") / exec(" << f.getRequiredExecGrade() << ") , target : "<< f.getTarget() << " ]";
	return (c);
}
