/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:55:10 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/11 13:46:35 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(int i = 1; i < argc; i++)
	{
		std::string new_str = argv[i];
		for(unsigned long j = 0; j < new_str.length(); j++)
			new_str[j] = std::toupper(new_str[j]);
		std::cout << new_str;
	}
	std::cout << std::endl;
	return (0);
}
