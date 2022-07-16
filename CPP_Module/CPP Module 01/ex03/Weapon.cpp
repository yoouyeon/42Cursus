/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:44:01 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/15 17:53:37 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string new_type) : type(new_type)
{
}

const std::string &Weapon::getType(void) const
{
	return (type);
}

void Weapon::setType(std::string new_type)
{
	type = new_type;
}
