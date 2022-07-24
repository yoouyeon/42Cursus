/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 01:02:37 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/23 19:56:43 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

// ANCHOR Constructors and Destructor, Canonical Form
Dog::Dog(void)
{
	type = "Dog";
	std::cout << "[Dog] Default constructor" << std::endl;
}

Dog::Dog(const Dog &origin)
{
	std::cout << "[Dog] Copy constructor" << std::endl;
	*this = origin;
}

Dog::~Dog(void)
{
	std::cout << "[Dog] Default destructor" << std::endl;
}

Dog &Dog::operator= (const Dog &origin)
{
	std::cout << "[Dog] Copy assignment operator" << std::endl;
	if (this != &origin)
		type = origin.getType();
	return (*this);
}

// ANCHOR Others
void Dog::makeSound(void) const
{
	std::cout << "Bow wow Bow wow" << std::endl;
}
