/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:17:18 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/26 01:04:23 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#define RED "\x1b[0;31m"
#define CYAN "\x1b[0;36m" 
#define RESET "\x1b[0m"

// constructor, canonical form
Intern::Intern(void)
{
	std::cout << "[ Intern Default Constructor called ]" << std::endl;
}

Intern::Intern(const Intern &origin)
{
	std::cout << "[ Intern Copy Constructor called ]" << std::endl;
	(void)origin;
}

Intern::~Intern(void)
{
	std::cout << "Intern is destroyed" << std::endl;
}

Intern &Intern::operator= (const Intern &origin)
{
	std::cout << "[ Intern Copy Assign operator called ]" << std::endl;
	(void)origin;
	return (*this);
}

// others
Form *Intern::makeForm(std::string name, std::string target) const
{
	int idx = (name == "shrubbery creation") * 1 + (name == "robotomy request") * 2 + (name == "presidential pardon") * 3;
	switch (idx)
	{
		case 1:
		{
			std::cout << CYAN << "Intern created " << name << " form" << RESET << std::endl;
			return new ShrubberyCreationForm(target);
		}
		case 2:
		{
			std::cout << CYAN << "Intern created " << name << " form" << RESET << std::endl;
			return new RobotomyRequestForm(target);
		}
		case 3:
		{
			std::cout << CYAN << "Intern created " << name << " form" << RESET << std::endl;
			return new PresidentialPardonForm(target);
		}
		default:
		{
			std::cout << RED << "Intern cannot found matching form" << RESET << std::endl;
			return NULL;
		}
	}
}
