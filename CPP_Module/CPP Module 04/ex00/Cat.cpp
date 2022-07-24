/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:34:12 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:34:28 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

// ANCHOR Constructors and Destructor, Canonical Form
Cat::Cat(void)
{
	type = "Cat";
	std::cout << "[Cat] Default constructor" << std::endl;
}

Cat::Cat(const Cat &origin)
{
	std::cout << "[Cat] Copy constructor" << std::endl;
	*this = origin;
}

Cat::~Cat(void)
{
	std::cout << "[Cat] Default destructor" << std::endl;
}

Cat &Cat::operator=(const Cat &origin)
{
	std::cout << "[Cat] Copy assignment operator" << std::endl;
	if (this != &origin)
		type = origin.getType();
	return (*this);
}

// ANCHOR Others
void Cat::makeSound(void) const
{
	std::cout << "Meow Meow Meow" << std::endl;
}
