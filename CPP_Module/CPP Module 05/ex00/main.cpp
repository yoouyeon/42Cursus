/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:23:58 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/26 15:51:20 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED "\x1b[0;31m"
#define UCYAN "\x1b[4;36m" 
#define RESET "\x1b[0m"

int main(void)
{
	{	
		std::cout << UCYAN << "---------- Bureaucrat constructor test ----------" << RESET << std::endl;
		try
		{
			for(int i = 149; i <= 151; i++)
				Bureaucrat tube("Tube", i); // 149, 150, 151
		} 
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << "\n";
		try
		{
			for(int i = 2; i >= 0; i--)
				Bureaucrat muzi("Muzi", i);	// 2, 1, 0
		}
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << UCYAN << "\n------------ Bureaucrat increase test -----------" << RESET << std::endl;
		Bureaucrat ryan("Ryan", 3);
		try
		{
			for(int i = 0; i < 3; i++)
			{
				ryan.increaseGrade();	//	2, 1, 0
				std::cout << ryan << RESET << std::endl;
			}
		} catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << UCYAN << "\n------------ Bureaucrat decrease test -----------" << RESET << std::endl;
		Bureaucrat apeach("Apeach", 148);
		try
		{
			for(int i = 0; i < 3; i++)
			{
				apeach.decreaseGrade();	// 149, 150, 151
				std::cout << apeach << std::endl;
			}
		} catch (std::exception & e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	return (0);
}
