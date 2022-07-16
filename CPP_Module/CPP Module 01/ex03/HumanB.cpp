/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:20:51 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/15 17:51:37 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(void) : name("Anonymous"), weapon(NULL)
{
}

HumanB::HumanB(std::string new_name) : name(new_name), weapon(NULL)
{
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}

void HumanB::attack(void)
{
	std::cout << name << " attacks with their ";
	if (weapon == NULL)
		std::cout << "hands" << std::endl;
	else
		std::cout << weapon->getType() << std::endl;
}
