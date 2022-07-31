/* ************************************************************************** */
/*                                                                            */
/*                         
                               :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 00:32:44 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/30 03:42:41 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "Span.hpp"

#define RED "\x1b[0;31m"
#define UCYAN "\x1b[4;36m"
#define CYAN "\x1b[0;36m"
#define RESET "\x1b[0m"

void printInside(const std::vector<int> &v)
{
	for(unsigned int i = 0; i < v.size(); i++)
		std::cout << v[i] << "\t";
	std::cout << std::endl;
}

int	main(void)
{
	{
		std::cout << UCYAN << "================= Subject Test ================" << RESET << std::endl;
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		printInside(sp.getData());
		std::cout << "shortestSpan : " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
	}

	{
		std::cout << UCYAN << "\n================ addNumber Test ===============" << RESET << std::endl;
		Span	sp = Span(5);

		sp.addNumber(1);
		sp.addNumber(5);
		sp.addNumber(3);

		std::cout << CYAN << "----- before addNumber -----" << RESET <<  std::endl;
		printInside(sp.getData());
		std::cout << "shortestSpan : " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;

		sp.addNumber(7);
		std::cout << CYAN << "----- after addNumber ------" << RESET << std::endl;
		printInside(sp.getData());
		std::cout << "shortestSpan : " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;

		std::cout << CYAN << "---- exception (single) ----" << RESET << std::endl;
		try
		{
			sp.addNumber(9);
			printInside(sp.getData());
			sp.addNumber(10);
			printInside(sp.getData());
		}
		catch (std::exception& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}

		std::cout << CYAN << "---- exception (range) -----" << RESET << std::endl;
		Span sp2(5);
		sp2.addNumber(1);
		std::vector<int> test;
		for(int i = 0; i < 6; i++)
			test.push_back(i);
		try
		{
			sp2.addNumber(test.begin(), test.end());
		}
		catch(std::exception& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << UCYAN << "\n================== span Test ==================" << RESET << std::endl;
		Span sp1;
		Span sp2(10);
		std::cout << CYAN << "-------- exception ---------" << RESET << std::endl;
		try
		{
			std::cout << "shortestSpan : " << sp1.shortestSpan() << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		try
		{
			std::cout << "longestSpan : " << sp2.longestSpan() << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
		std::cout << CYAN << "----------- span -----------" << RESET << std::endl;
		int temp = -3;
		for(int i = 0; i < 5; i++)
			sp2.addNumber(temp + i);
		printInside(sp2.getData());
		try
		{
			std::cout << "shortestSpan : " << sp2.shortestSpan() << std::endl;
			std::cout << "longestSpan : " << sp2.longestSpan() << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << UCYAN << "\n================== 10000 Test =================" << RESET << std::endl;
		std::list<int> test;
		for(int i = 0; i <= 10000; i++)
		{
			if (i % 2 == 0)
				test.push_back(i);
			else
				test.push_front(i);
		}
		Span sp(10001);
		sp.addNumber(test.begin(), test.end());
		std::cout << "shortestSpan : " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
	}

	return (0);
}

