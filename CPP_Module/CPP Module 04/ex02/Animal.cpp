/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:14:27 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 02:20:45 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

// ANCHOR Constructors and Destructor, Canonical Form
Animal::Animal(void) : type("Animal")
{
	std::cout << "[Animal] Default constructor" << std::endl;
}

Animal::Animal(const Animal &origin)
{
	std::cout << "[Animal] Copy constructor" << std::endl;
	*this = origin;
}

Animal::~Animal(void)
{
	std::cout << "[Animal] Default destructor" << std::endl;
}

Animal &Animal::operator=(const Animal &origin)
{
	std::cout << "[Animal] Copy assignment operator" << std::endl;
	if (this != &origin)
		type = origin.getType();
	return (*this);
}

// ANCHOR Accessor
std::string Animal::getType(void) const
{
	return (type);
}
