/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 00:18:53 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/16 16:21:44 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 4;
	Zombie *zombies = zombieHorde(N, "jeyoon");
	for(int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
