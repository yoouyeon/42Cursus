/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:34:07 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/26 15:57:19 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

#define RED "\x1b[0;31m"
#define BLUE "\x1b[0;34m"
#define GREEN "\x1b[0;32m"
#define MAGENTA "\x1b[0;35m"
#define RESET "\x1b[0m"

// ANCHOR constructor, canonical form
Bureaucrat::Bureaucrat(void) : _name("Default")
{
	std::cout << "[ Bureaucrat Default Constructor called ]" << std::endl;
	_grade = 150;
	std::cout << "Default Bureaucrat is created " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "[ Bureaucrat Constructor called ]" << std::endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade = grade;
	std::cout << "Bureaucrat is created " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &origin) : _name(origin.getName())
{
	std::cout << "[ Bureaucrat Copy Constructor called ]" << std::endl;
	_grade = origin.getGrade();
	std::cout << "Bureaucrat is copied " << *this << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << _name << " is destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &origin)
{
	std::cout << "[ Form Copy Assign operator called ]" << std::endl;
	if (this != &origin)
		_grade = origin.getGrade();
	std::cout << "Form is copied (only grade) " << *this << std::endl;
	return (*this);
}

// ANCHOR accessor
std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

// ANCHOR others

std::ostream &	operator<<(std::ostream &c, const Bureaucrat &b)
{
	c << "[ Bureaucrat name : " << b.getName() << ", grade : " << b.getGrade() << " ]";
	return (c);
}

void Bureaucrat::increaseGrade(void)
{
	// 1 is the highest, 150 is the lowest
	if (_grade == 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		_grade--;
	std::cout << MAGENTA << "Bureaucrat " << _name << "'s grade is increased (current : " << _grade << ")" << RESET << std::endl;
}

void Bureaucrat::decreaseGrade(void)
{
	// 1 is the highest, 150 is the lowest
	if (_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		_grade++;
	std::cout << BLUE << "Bureaucrat " << _name << "'s grade is decreased (current : " << _grade << ")" << RESET << std::endl;
}

void Bureaucrat::signForm(Form & f) const
{
	std::cout << GREEN << "Bureaucrat " << _name << " trying to sign the Form " << f.getName() << "...." << RESET << std::endl;
	try
	{
		f.beSigned(*this);
		std::cout << GREEN << "Bureaucrat " << _name << " signed the Form " << f.getName() << RESET << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << RED << "Bureaucrat " << _name << " couldn’t sign the Form " << f.getName() << " because " << e.what() << RESET << std::endl;
	}
}

// exception
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Error : Grade Is Too High");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Error : Grade Is Too Low");
}
