/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 04:34:07 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/25 20:22:21 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define BLUE "\x1b[0;34m"
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

// accessor
std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

// others
std::ostream &	operator<<(std::ostream &c, const Bureaucrat &b)
{
	c << "[ Bureaucrat name : " << b.getName() << ", grade : " << b.getGrade() << " ]";
	return (c);
}

void Bureaucrat::increaseGrade(void)
{
	// 1 is the highest, 150 is the lowest
	if (_grade == 1)
		throw(GradeTooHighException());
	else
		_grade--;
	std::cout << MAGENTA << "Bureaucrat " << _name << "'s grade is increased (current : " << _grade << ")" << RESET << std::endl;
}

void Bureaucrat::decreaseGrade(void)
{
	// 1 is the highest, 150 is the lowest
	if (_grade == 150)
		throw(GradeTooLowException());
	else
		_grade++;
	std::cout << BLUE << "Bureaucrat " << _name << "'s grade is decreased (current : " << _grade << ")" << RESET << std::endl;
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
