/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 01:02:37 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/23 23:34:33 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

// ANCHOR Constructors and Destructor, Canonical Form
Dog::Dog(void)
{
	std::cout << "[Dog] Default constructor" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &origin)
{
	std::cout << "[Dog] Copy constructor" << std::endl;
	type = origin.getType();
	_brain = new Brain();
	*_brain = *(origin.getBrain());
}

Dog::~Dog(void)
{
	std::cout << "[Dog] Default destructor" << std::endl;
	delete _brain;
}

Dog &Dog::operator= (const Dog &origin)
{
	std::cout << "[Dog] Copy assignment operator" << std::endl;
	if (this != &origin)
	{
		type = origin.getType();
		delete _brain;
		_brain = new Brain();
		*_brain = *(origin.getBrain());
	}
	return (*this);
}

// ANCHOR Accessor
Brain *Dog::getBrain(void) const
{
	return (_brain);
}

// ANCHOR Others
void Dog::makeSound(void) const
{
	std::cout << "Bow wow Bow wow" << std::endl;
}
