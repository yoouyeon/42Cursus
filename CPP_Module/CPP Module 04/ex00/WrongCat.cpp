/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:52:56 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:34:48 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

// ANCHOR Constructors and Destructor, Canonical Form
WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout << "[WrongCat] Default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &origin)
{
	std::cout << "[WrongCat] Copy constructor" << std::endl;
	*this = origin;
}

WrongCat::~WrongCat(void)
{
	std::cout << "[WrongCat] Default destructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &origin)
{
	std::cout << "[WrongCat] Copy assignment operator" << std::endl;
	if (this != &origin)
		type = origin.getType();
	return (*this);
}

// ANCHOR Others
void WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow Meow" << std::endl;
}
