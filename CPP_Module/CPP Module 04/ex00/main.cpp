/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:02:51 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:34:39 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		std::cout << "----------- Basic Test -----------" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << "\n----------- Wrong Test -----------" << std::endl;
		const WrongAnimal *a = new WrongCat();
		const WrongCat *c = new WrongCat();

		std::cout << a->getType() << std::endl;
		std::cout << c->getType() << std::endl;
		a->makeSound();
		c->makeSound();

		delete a;
		delete c;
	}
	return (0);
}
