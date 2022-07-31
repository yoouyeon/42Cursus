/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 00:32:48 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/31 02:55:04 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <limits>
#include "Span.hpp"

// Constructor

Span::Span(void) : _max_size(0) { };

Span::Span(unsigned int max_size) : _max_size(max_size) { };

Span::Span(const Span &origin) : _max_size(origin.getMaxSize())
{
	_data = origin.getData();
}
Span::~Span(void) { };

Span &Span::operator =(const Span &origin)
{
	if (this == &origin)
		return (*this);
	_max_size = origin.getMaxSize();
	_data = origin.getData();
	return (*this);
}

// accessor
unsigned int Span::getMaxSize(void) const { return (_max_size); }

const std::vector<int> &Span::getData(void) const { return (_data); }

// others
void Span::addNumber(int num)
{
	if (_data.size() == _max_size)
		throw (Span::NoFreeSpaceException());
	else
		_data.push_back(num);
}

int Span::shortestSpan(void) const
{
	if (_data.empty() || _data.size() == 1)
		throw (Span::NoSpanFoundException());
	std::vector<int> copy_data(_data);
	std::sort(copy_data.begin(), copy_data.end());
	int shortest = std::numeric_limits<int>::max();
	std::vector<int>::iterator prev = copy_data.begin();
	std::vector<int>::iterator next = prev + 1;
	while (next != copy_data.end())
	{
		shortest = std::min(shortest, *next - *prev);
		prev = next;
		next = prev + 1;
	}
	return (shortest);
}

int Span::longestSpan(void) const
{
	if (_data.empty() || _data.size() == 1)
		throw(Span::NoSpanFoundException());
	int min_ele = *std::min_element(_data.begin(), _data.end());
	int max_ele = *std::max_element(_data.begin(), _data.end());
	return (max_ele - min_ele);
}

// exceptions

const char *Span::NoFreeSpaceException::what(void) const throw()
{
	return ("There is not enough free space.");
}

const char *Span::NoSpanFoundException::what(void) const throw()
{
	return ("There are not enough elements to find the span.");
}
