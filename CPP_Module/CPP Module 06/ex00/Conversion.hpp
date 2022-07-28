/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:00:51 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/27 21:43:25 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <string>
#include <exception>

namespace conversion
{
	void printChar(std::string str);
	void printInt(std::string str);
	void printFloat(std::string str);
	void printDouble(std::string str);

	class ImpossibleConversion : public std::exception
	{
		public :
			const char* what(void) const throw();
	};
}

#endif