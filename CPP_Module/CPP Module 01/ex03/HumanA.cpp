/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:16:01 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/15 17:51:30 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(Weapon &new_weapon) : name("Anonymous"), weapon(new_weapon)
{

}

HumanA::HumanA(std::string new_name, Weapon &new_weapon) : name(new_name), weapon(new_weapon)
{

}

void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
