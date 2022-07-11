/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:00:26 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/11 02:34:35 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

void phonebookutils::GetInputWithPrompt(std::string prompt, std::string *input_str)
{
	while(1)
	{
		std::cout << prompt;
		std::getline(std::cin, *input_str);
		if (!std::cin.good())
			std::exit(1);
		else if ((*input_str).empty())
		{
			std::cout << " Error : contact can’t have empty fields." << std::endl;
			continue ;
		}
		else
			break ;
	}
}

void phonebookutils::GetInputWithPrompt(std::string prompt, int *input_num)
{
	std::string input_str;
	while(1)
	{
		std::cout << prompt;
		std::getline(std::cin, input_str);
		if (!std::cin.good())
			std::exit(1);
		else if (input_str.empty())
		{
			std::cout << " Error : empty input." << std::endl;
			continue ;
		}
		else
		{
			std::stringstream ss(input_str);
			ss >> *input_num;
			if (ss.fail() || ss.bad() || (*input_num < 0 || *input_num > 7))
			{
				std::cout << " Error : enter a number from 0 to 7." << std::endl;
				continue ;
			}
			else
				break ;
		}
	}
}

void phonebookutils::FormattedPrint(std::string str)
{
	std::string output = str;
	if(output.length() > 10)
		output[9] = '.';
	std::cout << std::setw(10) << output.substr(0, 10) << '|';	
}
