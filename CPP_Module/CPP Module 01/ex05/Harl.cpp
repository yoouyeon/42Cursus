/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:58:46 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/16 16:57:54 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

void Harl::debug(void)
{
	std::cout << "[DEBUG]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n";
	std::cout << "I really do!\n";
}

void Harl::info(void)
{
	std::cout << "[INFO]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn’t put enough bacon in my burger!\n";
	std::cout << "If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{

	std::cout << "[WARNING]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "[ERROR]\n";
	std::cout << "This is unacceptable!\n";
	std::cout << "I want to speak to the manager now.\n";
}

Harl::Harl(void)
{
	fp[0] = &Harl::debug;
	fp[1] = &Harl::info;
	fp[2] = &Harl::warning;
	fp[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	int idx = ((level == "DEBUG") * 1 + (level == "INFO") * 2 + (level == "WARNING") * 3 + (level == "ERROR") * 4);
	if (idx == 0)
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	else
		(this->*fp[idx - 1])();
}