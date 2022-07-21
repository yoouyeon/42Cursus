/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:24:30 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/21 16:33:20 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

/*
*	ANCHOR Constructor, Destructor
*/

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value * (1 << _frac_bits);
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _frac_bits));
}
Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
*	ANCHOR Operator
*/

Fixed&  Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_value = fixed.getRawBits();
	return *this;
}

/*
*	ANCHOR Accessor
*/

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

/*
*	ANCHOR Others
*/

float Fixed::toFloat( void ) const
{
	return (float(_value) / (1 << _frac_bits));
}

int Fixed::toInt( void ) const
{
	return (_value / (1 << _frac_bits));
}

std::ostream &	operator<<(std::ostream &c, const Fixed &fixed)
{
	c << fixed.toFloat();
	return (c);
}
