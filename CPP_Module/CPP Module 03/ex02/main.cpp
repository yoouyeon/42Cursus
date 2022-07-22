/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:51:17 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/22 19:06:59 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap fs("Tube");

	std::cout << "----------------------------------------" << std::endl;
	for(int i = 0; i < 5; i++)
		fs.attack("Ryan");
	for(int i = 0; i < 3; i++)
		fs.takeDamage(30);
	fs.highFivesGuys();
	fs.beRepaired(30);
	for(int i = 0; i < 2; i++)
		fs.takeDamage(30);
	fs.highFivesGuys();
	std::cout << "----------------------------------------" << std::endl;
	
	return (0);
}
