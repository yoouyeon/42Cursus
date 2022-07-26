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

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

#define RED "\x1b[0;31m"
#define UCYAN "\x1b[4;36m" 
#define RESET "\x1b[0m"

int main(void)
{
	{	
		std::cout << UCYAN << "---------- Form construction test ----------" << RESET << std::endl;
		try
		{
			for(int i = 149; i <= 151; i++)
				Form kakao("Kakao", i, 10);	// sign grade : 149, 150, 151
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "\n";
		try
		{
			for(int i = 2; i >= 0; i--)
				Form kakao_friends("Kakao Friends", 10, i);	// exec grade 2, 1, 0
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << UCYAN << "\n------------ Form sign test -----------" << RESET << std::endl;
		Bureaucrat ryan("Ryan", 43);
		Form kakao ("Kakao", 40, 40);
		std::cout << "\n";
		for(int i = 0; i < 3; i++)
		{
			ryan.increaseGrade(); // sign grade : 42, 41, 40
			ryan.signForm(kakao);
			std::cout << kakao << "\n\n";
		}
	}
	return (0);
}
