/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:27:43 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/22 19:08:37 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

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

ScavTrap::ScavTrap(void)
{
	_name = "Anonymous";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "Default ScavTrap is created " << "(" << _name << ")" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
{
	_name = name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap is created " << "(" << _name << ")" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	*this = src;
	std::cout << "ScavTrap is copied " << "(" << _name << ")" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap is destroyed " << "(" << _name << ")" << std::endl;
}

ScavTrap &ScavTrap::operator =(const ScavTrap &src)
{
	if (this != &src)
	{
		_name = src.getName();
		_hit_points = src.getHitPoints();
		_energy_points = src.getEnergyPoints();
		_attack_damage = src.getAttackDamage();
	}
	std::cout << "ScavTrap's copy assignment operator called" << "(" << _name << ")" << std::endl;
	return (*this);
}

/*
*	ANCHOR Others
*/

void ScavTrap::attack(const std::string& target)
{
	if (_hit_points == 0)
	{
		std::cout << RED << "[!] ScavTrap " << _name << " is already dead" << RESET << std::endl;
		return ;
	}
	else if (_energy_points == 0)
	{
		std::cout << RED << "[!] ScavTrap " << _name << "'s Energy Point is Zero" << RESET << std::endl;
		return ;
	}
	_energy_points--;
	std::cout << MAGENTA << "[*] ScavTrap " << _name << " --> " << target << " (attack damage : " << _attack_damage << ")" << RESET << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (_hit_points == 0 || _energy_points == 0)
		std::cout << RED << "[!] ScavTrap " << _name << " is cannot in Gate keeper mode. (Energy Point or Hit Point is Zero)" << RESET << std::endl;
	else
		std::cout << BLUE << "[@] ScavTrap " << _name << "  is now in Gate keeper mode." << RESET << std::endl;
}
