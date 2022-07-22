/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:51:11 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/22 19:08:37 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

#define RED "\x1b[0;31m"
#define GREEN "\x1b[0;32m"
#define YELLOW "\x1b[0;33m"
#define MAGENTA "\x1b[0;35m"
#define RESET "\x1b[0m"

/*
*	ANCHOR constructor, canonical form
*/

ClapTrap::ClapTrap(void)
{
	_name = "Anonymous";
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "Default ClapTrap is created " << "(" << _name << ")" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
{
	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "ClapTrap is created " << "(" << _name << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	*this = ct;
	std::cout << "ClapTrap is copied " << "(" << _name << ")" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap is destroyed " << "(" << _name << ")" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct)
{
	if (this != &ct)
	{
		_name = ct.getName();
		_hit_points = ct.getHitPoints();
		_energy_points = ct.getEnergyPoints();
		_attack_damage = ct.getAttackDamage();
	}
	std::cout << "ClapTrap's copy assignment operator called" << "(" << _name << ")" << std::endl;
	return (*this);
}

/*
*	ANCHOR Accessor
*/

std::string ClapTrap::getName(void) const
{
	return (_name);
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (_hit_points);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (_energy_points);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (_attack_damage);
}

/*
*	ANCHOR Others
*/

void ClapTrap::attack(const std::string& target)
{
	if (_hit_points == 0)
	{
		std::cout << RED << "[!] ClapTrap " << _name << " is already dead" << RESET << std::endl;
		return ;
	}
	else if (_energy_points == 0)
	{
		std::cout << RED << "[!] ClapTrap " << _name << "'s Energy Point is Zero" << RESET << std::endl;
		return ;
	}
	_energy_points--;
	std::cout << MAGENTA << "[*] ClapTrap " << _name << " --> " << target << " (attack damage : " << _attack_damage << ")" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points == 0)
		std::cout << RED << "[!] ClapTrap " << _name << " is already dead (not damaged)" << RESET << std::endl;
	else if (_hit_points <= amount)
	{
		std::cout << YELLOW << "[-] ClapTrap " << _name << " died (Hit point loss : " << _hit_points << ")" << RESET << std::endl;
		_hit_points = 0;
	}
	else
	{
		_hit_points -= amount;
		std::cout << YELLOW << "[-] ClapTrap " << _name << " got damaged (Hit point loss : " << amount << " / current : " << _hit_points << ")" << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points == 0)
	{
		std::cout << RED << "[!] ClapTrap " << _name << " is already dead" << RESET << std::endl;
		return ;
	}
	else if (_energy_points == 0)
	{
		std::cout << RED << "[!] ClapTrap " << _name << "'s Energy Point is Zero" << RESET << std::endl;
		return ;
	}
	_energy_points--;
	_hit_points += amount;
	std::cout << GREEN << "[+] ClapTrap " << _name << " repaired itself (Hit point gain : " << amount << " / current : " << _hit_points << ")" << RESET << std::endl;
}
