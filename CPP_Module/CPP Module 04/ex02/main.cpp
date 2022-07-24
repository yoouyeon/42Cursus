/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:02:51 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:37:15 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define YELLOW "\x1b[0;33m"
#define RESET "\x1b[0m"

int main(void)
{
	// ANCHOR Basic Test
	{
		std::cout << YELLOW << "----------- Basic Test -----------" << RESET << std::endl;
		//const Animal *a = new Animal();
		const Animal *d = new Dog();
		const Animal *c = new Cat();

		std::cout << d->getType() << std::endl;
		std::cout << c->getType() << std::endl;

		d->makeSound();
		c->makeSound();

		delete d;
		delete c;
	}
	return (0);
}
