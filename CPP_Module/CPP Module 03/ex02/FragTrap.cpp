/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:09:35 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/22 19:08:37 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

#define RED "\x1b[0;31m"
#define GREEN "\x1b[0;32m"
#define YELLOW "\x1b[0;33m"
#define BLUE "\x1b[0;34m"
#define MAGENTA "\x1b[0;35m"
#define CYAN "\x1b[0;36m"
#define RESET "\x1b[0m"

/*
*	ANCHOR Constructor, Destructor
*/

FragTrap::FragTrap(void)
{
	_name = "Anonymous";
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "Default FragTrap is created " << "(" << _name << ")" << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	_name = name;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "Default FragTrap is created " << "(" << _name << ")" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
{
	*this = src;
	std::cout << "FragTrap is copied " << "(" << _name << ")" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap is destroyed " << "(" << _name << ")" << std::endl;
}

FragTrap &FragTrap::operator =(const FragTrap &src)
{
	if (this != &src)
	{
		_name = src.getName();
		_hit_points = src.getHitPoints();
		_energy_points = src.getEnergyPoints();
		_attack_damage = src.getAttackDamage();
	}
	std::cout << "FragTrap's copy assignment operator called" << "(" << _name << ")" << std::endl;
	return (*this);
}

/*
*	ANCHOR Others
*/

void FragTrap::highFivesGuys(void)
{
	if (_hit_points == 0 || _energy_points == 0)
		std::cout << RED << "[!] FragTrap " << _name << " cannot send positive high fives request (Energy Point or Hit Point is Zero)" << RESET << std::endl;
	else
		std::cout << BLUE << "[@] FragTrap " << _name << " sent positive high fives request" << RESET << std::endl;
}
