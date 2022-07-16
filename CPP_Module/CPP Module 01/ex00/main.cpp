/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:04:48 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/15 17:38:07 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	std::cout << "********** TEST Constructor ***********" << std::endl;
	Zombie z1 = Zombie();
	z1.announce();
	Zombie z2 = Zombie("Iron Man");
	z2.announce();

	std::cout << "\n******* TEST function newZombie *******" << std::endl;
	Zombie *z3 = newZombie("Natasha");
	z3->announce();
	z3->set_name("Black Widow");
	z3->announce();
	delete z3;

	std::cout << "\n****** TEST function randomChump ******" << std::endl;
	randomChump("Dr. Strange");

	return (0);
}
