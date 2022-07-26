/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:23:58 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/26 15:50:51 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RED "\x1b[0;31m"
#define UCYAN "\x1b[4;36m" 
#define RESET "\x1b[0m"

int main(void)
{
	Bureaucrat b1("Master", 1);
	Bureaucrat b2("Gold", 10);
	Bureaucrat b3("Silver", 60);
	Bureaucrat b4("Bronze", 140);
	Bureaucrat b5("UnRanked", 150);

	std::cout << "\n";

	std::cout << UCYAN << "\n---------- ShrubberyCreationForm test ----------" << RESET << std::endl;
	ShrubberyCreationForm s("green");
	b3.executeForm(s);	// cannot execute (not signed)
	b5.signForm(s);	// cannot sign (low grade)
	b4.signForm(s);	// sign
	std::cout << s << std::endl;
	b1.executeForm(s);	// execute
	b2.executeForm(s);	// execute
	b3.executeForm(s);	// execute
	b4.executeForm(s);	// cannot execute
	b5.executeForm(s);	// cannot execute

	std::cout << UCYAN << "\n----------- RobotomyRequestForm test -----------" << RESET << std::endl;
	RobotomyRequestForm r("robo");
	b2.executeForm(r);	// cannot execute (not signed)
	b4.signForm(r);	// cannot sign (low grade)
	b3.signForm(r);	// sign
	std::cout << r << std::endl;
	b1.executeForm(r);	// execute
	b2.executeForm(r);	// execute
	b3.executeForm(r);	// cannot execute
	b4.executeForm(r);	// cannot execute
	b5.executeForm(r);	// cannot execute

	std::cout << UCYAN << "\n--------- PresidentialPardonForm test ----------" << RESET << std::endl;
	PresidentialPardonForm p("bye");
	b1.executeForm(p);	// cannot execute (not signed)
	b3.signForm(p);	// cannot sign (low grade)
	b2.signForm(p);	// sign
	std::cout << p << std::endl;
	b1.executeForm(p);	// execute
	b2.executeForm(p);	// cannot execute
	b3.executeForm(p);	// cannot execute
	b4.executeForm(p);	// cannot execute
	b5.executeForm(p);	// cannot execute

	return (0);
}
