
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:39:07 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/27 10:39:07 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Only one argument is allowed." << std::endl;
		return (0);
	}
	std::cout << std::showpoint;
	conversion::printChar(argv[1]);
	conversion::printInt(argv[1]);
	conversion::printFloat(argv[1]);
	conversion::printDouble(argv[1]);

	return (0);
}