/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:48:28 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/21 16:55:43 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
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
*	ANCHOR Operator =, <<
*/

Fixed&  Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_value = fixed.getRawBits();
	return *this;
}

std::ostream &	operator<<(std::ostream &c, const Fixed &fixed)
{
	c << fixed.toFloat();
	return (c);
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

/*
*	ANCHOR comparison operator
*/

bool Fixed::operator<(const Fixed &fixed) const
{
	return (_value < fixed.getRawBits());
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (_value > fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (_value >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (_value <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (_value == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (_value != fixed.getRawBits());
}

/*
*	ANCHOR  arithmetic operator
*/

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed ret;
	ret.setRawBits(_value + fixed.getRawBits());
	return (ret);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed ret;
	ret.setRawBits(_value - fixed.getRawBits());
	return (ret);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed ret(toFloat() * fixed.toFloat());
	return (ret);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	if (fixed.getRawBits() == 0)
	{
		std::cout << "Error : Division by zero" << std::endl;
		std::exit(1);
	}
	Fixed ret(toFloat() / fixed.toFloat());
	return (ret);	
}

/*
*	ANCHOR increment/decrement operator
*/

Fixed &Fixed::operator++(void)
{
	_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed ret(*this);
	_value++;
	return (ret);
}

Fixed &Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed ret(*this);
	_value--;
	return (ret);
}

/*
*	ANCHOR min, max
*/
Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 <= f2)
		return (f1);
	else
		return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 <= f2)
		return (f1);
	else
		return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 >= f2)
		return (f1);
	else
		return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 >= f2)
		return (f1);
	else
		return (f2);
}
