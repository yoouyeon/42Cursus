/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:51:17 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/22 19:06:12 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap tc("Tube");

	std::cout << "----------------------------------------" << std::endl;
	for(int i = 0; i < 6; i++)
		tc.attack("Ryan");
	for(int i = 0; i < 6; i++)
		tc.takeDamage(1);
	for(int i = 0; i < 6; i++)
		tc.beRepaired(1);
	std::cout << "----------------------------------------" << std::endl;
	
	return (0);
}
