/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:00:44 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/30 15:47:35 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "Conversion.hpp"

/*	=========================================================================

	서브젝트에서 요구한 방식과 다른 방식으로 풀었다.
	서브젝트에서는
	1. 인자로 들어오는 것의 타입을 판별하고
	2. 그 외의 3개의 타입으로 명시적으로 변환하라고 했다.
	따라서 아래와 같이 일괄적으로 char를 먼저 처리한 뒤에, double로 바꾸는 풀이는 서브젝트의 요구
	사항과 맞지 않다.

	요구사항에 맞추려면
	1. char인지 확인 (길이 1, 숫자 아님)	-> 변환하여 출력
	2. int인지 확인 (숫자 뿐이고 int 범위 내인 경우)	-> 변환하여 출력
	3. float인지 확인 (숫자와 문자 . 1개, f 1개가 있는 경우)	-> 변환하여 출력
	4. double인지 확인 (숫자와 문자 . 1개가 있는 경우)	-> 변환하여 출력
	이렇게 차례차례 확인하면서 맞는 단계에 바로 출력을 해 줬어야 했을 것 같다.

	========================================================================= */

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
