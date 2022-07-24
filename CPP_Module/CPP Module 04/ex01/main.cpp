/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:02:51 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:36:15 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define YELLOW "\x1b[0;33m"
#define GREEN "\x1b[0;32m"
#define RESET "\x1b[0m"

int main(void)
{
	// ANCHOR Basic Test
	{
		std::cout << YELLOW << "----------- Basic Test -----------" << RESET << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;//should not create a leak
		delete i;
	}
	// ANCHOR Deep Copy Test
	std::cout << YELLOW << "\n---------- Deep Copy Test --------" << RESET << std::endl;
	{
		std::cout << GREEN << "=== TEST Dog ===" << RESET << std::endl;
		Dog D1;
		D1.getBrain()->setIdea(0, "Walk");

		Dog D2(D1);
		Dog D3;
		D3 = D1;

		std::cout << "[Before]" << std::endl;
		std::cout << "D1 : " << D1.getBrain()->getIdea(0) << std::endl;
		std::cout << "D2 : " << D2.getBrain()->getIdea(0) << std::endl;
		std::cout << "D3 : " << D3.getBrain()->getIdea(0) << std::endl;

		D1.getBrain()->setIdea(0, "Play");
		std::cout << "[After]" << std::endl;
		std::cout << "D1 : " << D1.getBrain()->getIdea(0) << std::endl;
		std::cout << "D2 : " << D2.getBrain()->getIdea(0) << std::endl;
		std::cout << "D3 : " << D3.getBrain()->getIdea(0) << std::endl;
	}
	{
		std::cout << GREEN << "\n=== TEST Cat ===" << RESET << std::endl;
		Cat C1;
		C1.getBrain()->setIdea(0, "Box");

		Cat C2(C1);
		Cat C3;
		C3 = C1;

		std::cout << "[Before]" << std::endl;
		std::cout << "D1 : " << C1.getBrain()->getIdea(0) << std::endl;
		std::cout << "D2 : " << C2.getBrain()->getIdea(0) << std::endl;
		std::cout << "D3 : " << C3.getBrain()->getIdea(0) << std::endl;

		C1.getBrain()->setIdea(0, "Can");
		std::cout << "[After]" << std::endl;
		std::cout << "C1 : " << C1.getBrain()->getIdea(0) << std::endl;
		std::cout << "C2 : " << C2.getBrain()->getIdea(0) << std::endl;
		std::cout << "C3 : " << C3.getBrain()->getIdea(0) << std::endl;
	}
	// ANCHOR Subject Test
	{
		std::cout << YELLOW << "\n--------- Subject Test ----------" << RESET << std::endl;
		Animal *array[4];
		for(int i = 0; i < 4; i++)
		{
			if (i % 2 == 0)
				array[i] = new Dog();
			else
				array[i] = new Cat();
		}
		std::cout << "=================================" << std::endl;
		for(int i = 0; i < 4; i++)
			array[i]->makeSound();
		std::cout << "=================================" << std::endl;
		for(int i = 0; i < 4; i++)
			delete array[i];
	}
	return (0);
}
