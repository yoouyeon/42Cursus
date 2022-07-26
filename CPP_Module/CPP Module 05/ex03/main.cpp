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

#include "Intern.hpp"

int main(void)
{
	Intern jeyoon;
	Form *form;
	std::cout << std::endl;
	
	form = jeyoon.makeForm("shrubbery creation", "CPP Module");
	delete form;
	std::cout << std::endl;
	form = jeyoon.makeForm("robotomy request", "CPP Module");
	delete form;
	std::cout << std::endl;
	form = jeyoon.makeForm("presidential pardon", "CPP Module");
	delete form;
	std::cout << std::endl;
	form = jeyoon.makeForm("blah blah", "CPP Module");
	delete form;
	
	return (0);
}
