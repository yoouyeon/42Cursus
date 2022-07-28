/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:00:44 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/28 16:43:47 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "Conversion.hpp"

const char* conversion::ImpossibleConversion::what(void) const throw()
{
	return ("impossible");
}

static double stringToDouble(std::string str)
{
	char *ptr;
	if (str.length() == 0)
		throw (conversion::ImpossibleConversion());
	double ret = strtod(str.c_str(), &ptr);
	if (errno == ERANGE) // overflow, underflow
	{
		errno = 0;
		throw (conversion::ImpossibleConversion());
	}
	else if (*ptr != '\0' && *ptr != 'f')	// xxxf
		throw (conversion::ImpossibleConversion());
	else if (*ptr != '\0' && *(ptr + 1) != '\0') // xxxff
		throw (conversion::ImpossibleConversion());
	else
		return (ret);
}

void conversion::printChar(std::string str)
{
	std::cout << "char: ";
	// char
	if (str.length() == 1 && std::isdigit(str[0]) == 0 && std::isprint(str[0]) != 0)
	{
		std::cout << '\'' << str[0] << '\'' << std::endl;
		return ;
	}
	// num
	try
	{
		double tempD = stringToDouble(str);
		if (tempD != tempD)	//	nan
			std::cout << "impossible" << std::endl;
		else if (tempD < std::numeric_limits<char>::min() \
			|| tempD > std::numeric_limits<char>::max())	// out of range
			std::cout << "impossible" << std::endl;
		else if (isprint(static_cast<int>(tempD)) == 0)	// Non displayable
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << '\'' << static_cast<char>(tempD) << '\'' << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void conversion::printInt(std::string str)
{
	std::cout << "int: ";
	// char
	if (str.length() == 1 && std::isdigit(str[0]) == 0 && std::isprint(str[0]) != 0)
	{
		std::cout << static_cast<int>(str[0]) << std::endl;
		return ;
	}
	// num
	try
	{
		double tempD = stringToDouble(str);
		if (tempD != tempD)	//	nan
			std::cout << "impossible" << std::endl;
		else if (tempD < std::numeric_limits<int>::min() \
			|| tempD > std::numeric_limits<int>::max())	// out of range
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(tempD) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void conversion::printFloat(std::string str)
{
	std::cout << "float: ";
	// char
	if (str.length() == 1 && std::isdigit(str[0]) == 0 && std::isprint(str[0]) != 0)
	{
		std::cout << static_cast<float>(str[0]) << "f" << std::endl;
		return ;
	}
	// num
	try
	{
		double tempD = stringToDouble(str);
		if (tempD != tempD)	//	nan
			std::cout << "nanf" << std::endl;
		else if (tempD == std::numeric_limits<double>::infinity())
			std::cout << "inff" << std::endl;
		else if (tempD == std::numeric_limits<double>::infinity() * (-1))
			std::cout << "-inff" << std::endl;
		else if (tempD < std::numeric_limits<float>::max() * (-1) \
			|| tempD > std::numeric_limits<float>::max())	// out of range
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<float>(tempD) << "f" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void conversion::printDouble(std::string str)
{
	std::cout << "double: ";
	// char
	if (str.length() == 1 && std::isdigit(str[0]) == 0 && std::isprint(str[0]) != 0)
	{
		std::cout << static_cast<double>(str[0]) << std::endl;
		return ;
	}
	// num
	try
	{
		double tempD = stringToDouble(str);
		if (tempD != tempD)	//	nan
			std::cout << "nan" << std::endl;
		else if (tempD == std::numeric_limits<double>::infinity())
			std::cout << "inf" << std::endl;
		else if (tempD == std::numeric_limits<double>::infinity() * (-1))
			std::cout << "-inf" << std::endl;
		else
			std::cout << tempD << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
