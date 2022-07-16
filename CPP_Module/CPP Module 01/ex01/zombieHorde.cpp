/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:59:09 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/15 17:48:27 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		std::cout << "Error : N must be greater than 0" << std::endl;
		return (NULL);
	}
	Zombie *zombies = new Zombie[N];
	for(int i = 0; i < N; i++)
		zombies[i].set_name(name);
	return (zombies);
}
