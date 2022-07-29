/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   main.cpp	   :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: jeyoon <jeyoon@student.42seoul.kr>	 +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2022/07/29 01:43:24 by jeyoon	#+#	#+#	 */
/*   Updated: 2022/07/29 14:09:48 by jeyoon	   ###   ########seoul.kr  */
/*	*/
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define RED "\x1b[0;31m"
#define UCYAN "\x1b[4;36m"
#define CYAN "\x1b[0;36m"
#define RESET "\x1b[0m"
#define MAX_VAL 750

int main(void)
{
	// ANCHOR Subject Test
	{
		std::cout << UCYAN << "================= Subject Test ================" << RESET << std::endl;
		Array<int> numbers(MAX_VAL);	// custom array class
		int* mirror = new int[MAX_VAL];	// int array
		// make random value
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			// copy assignment
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		// [] operator test
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	// ANCHOR Constructor Test
	{
		std::cout << UCYAN << "=============== Constructor Test ==============" << RESET << std::endl;
		std::cout << CYAN << "----- Default -----" << RESET << std::endl;
		Array<int> a;
		std::cout << a.size() << std::endl;
		try
		{
			std::cout << a[0] << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << RED << "Exception Occurred" << RESET << std::endl;
		}
		std::cout << CYAN << "------ Size -------" << RESET << std::endl;
		Array<unsigned int> b(4);
		Array<unsigned int> c(0);
		std::cout << b.size() << std::endl;
		std::cout << c.size() << std::endl;
	}
	// ANCHOR Deep Copy Test
	{
		std::cout << UCYAN << "=================== Copy Test =================" << RESET << std::endl;
		Array<char> a(5);
		for(int i = 0; i < 5; i++)
			a[i] = static_cast<char>(i + 48);
		Array<char> b(a); // copy constructor
		Array<char> c;
		c = a;	// copy assign operator
		std::cout << CYAN << "----- Before ------" << RESET << std::endl;
		std::cout << "a :\t";
		for(int i = 0; i < 5; i++)
			std::cout << a[i] << "\t";
		std::cout << "\nb :\t";
		for(int i = 0; i < 5; i++)
			std::cout << b[i] << "\t";
		std::cout << "\nc :\t";
		for(int i = 0; i < 5; i++)
			std::cout << c[i] << "\t";
		std::cout << '\n';

		for(int i = 0; i < 5; i++)
			b[i] = static_cast<char>(i + 65);
		for(int i = 0; i < 5; i++)
			c[i] = static_cast<char>(i + 97);

		std::cout << CYAN << "------ After ------" << RESET << std::endl;
		std::cout << "a :\t";
		for(int i = 0; i < 5; i++)
			std::cout << a[i] << "\t";
		std::cout << "\nb :\t";
		for(int i = 0; i < 5; i++)
			std::cout << b[i] << "\t";
		std::cout << "\nc :\t";
		for(int i = 0; i < 5; i++)
			std::cout << c[i] << "\t";
		std::cout << '\n';
	}
	{
		std::cout << UCYAN << "================= [] operator =================" << RESET << std::endl;
		const std::string str_array[5] = {"gaga", "nana", "dada", "rara", "mama"};
		Array<std::string> a(5);
		for(int i = 0; i < 5; i++)
			a[i] = str_array[i];
		try
		{
			for(int i = 0; i < 6; i++)
				std::cout << a[i] << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << RED << "Exception Occurred" << RESET << std::endl;
		}
		a[0] = "agag";
		try
		{
			for(int i = 4; i >= -1; i--)
				std::cout << a[i] << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << RED << "Exception Occurred" << RESET << std::endl;
		}
		std::cout << CYAN << "-------------------" << RESET << std::endl;
		const Array<int> b(2);
		std::cout << b[0] << std::endl;
		//b[0] = 42;
	}
	return (0);
}