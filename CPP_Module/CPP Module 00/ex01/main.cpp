/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:05:39 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/11 13:47:25 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook my_phonebook;
	std::string input;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (!std::cin.good() || input == "EXIT")
			break;
		else if (input == "ADD")
			my_phonebook.Add();
		else if (input == "SEARCH")
			my_phonebook.Search();
		else
			continue;
	}
	return (0);
}
