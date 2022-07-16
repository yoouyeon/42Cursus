/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:58:58 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/15 17:49:25 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

/*
*	Constructor, Destructor
*/

Zombie::Zombie(void) : _name("Anonymous")
{
}

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie(void)
{
	std::cout << _name << " is died..." << std::endl;
}

/*
*	Accessor
*/

void Zombie::set_name(std::string name)
{
	_name = name;
}

std::string Zombie::get_name(void) const
{
	return (_name);
}

/*
*	Others
*/

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
