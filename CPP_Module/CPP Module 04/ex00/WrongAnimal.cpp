/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:52:52 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:34:42 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

// ANCHOR Constructors and Destructor, Canonical Form
WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "[WrongAnimal] Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &origin)
{
	std::cout << "[WrongAnimal] Copy constructor" << std::endl;
	*this = origin;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "[WrongAnimal] Default destructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &origin)
{
	std::cout << "[WrongAnimal] Copy assignment operator" << std::endl;
	if (this != &origin)
		type = origin.getType();
	return (*this);
}

// ANCHOR Accessor
std::string WrongAnimal::getType(void) const
{
	return (type);
}

// ANCHOR Others
void WrongAnimal::makeSound(void) const
{
	std::cout << "Sound of a mysterious WrongAnimal" << std::endl;
}
