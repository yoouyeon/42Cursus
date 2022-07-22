/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:51:17 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/22 19:06:24 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap ts("Tube");

	std::cout << "----------------------------------------" << std::endl;
	for(int i = 0; i < 10; i++)
		ts.attack("Ryan");
	for(int i = 0; i < 4; i++)
		ts.takeDamage(20);
	ts.guardGate();
	ts.beRepaired(20);
	for(int i = 0; i < 2; i++)
		ts.takeDamage(20);
	ts.guardGate();
	std::cout << "----------------------------------------" << std::endl;
	
	return (0);
}
