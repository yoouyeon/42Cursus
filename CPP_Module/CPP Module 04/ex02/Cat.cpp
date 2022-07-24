/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:34:12 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:37:15 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

// ANCHOR Constructors and Destructor, Canonical Form
Cat::Cat(void)
{
	std::cout << "[Cat] Default constructor" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &origin)
{
	std::cout << "[Cat] Copy constructor" << std::endl;
	type = origin.getType();
	_brain = new Brain();
	*_brain = *(origin.getBrain());
}

Cat::~Cat(void)
{
	std::cout << "[Cat] Default destructor" << std::endl;
	delete _brain;
}

Cat &Cat::operator=(const Cat &origin)
{
	std::cout << "[Cat] Copy assignment operator" << std::endl;
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
Brain *Cat::getBrain(void) const
{
	return (_brain);
}

// ANCHOR Others
void Cat::makeSound(void) const
{
	std::cout << "Meow Meow Meow" << std::endl;
}
