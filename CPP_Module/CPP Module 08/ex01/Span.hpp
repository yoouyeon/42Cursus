/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 00:32:50 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/31 12:16:56 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <vector>

class Span
{
	private:
		unsigned int _max_size;
		std::vector<int> _data;

	public:
		// constructor, canonical form
		Span(void);
		Span(unsigned int max_size);
		Span(const Span &origin);
		~Span(void);
		Span &operator =(const Span &origin);
		// accessor
		unsigned int getMaxSize(void) const;
		const std::vector<int> &getData(void) const;
		// others
		void addNumber(int num);
		template <typename Iter>
		void addNumber(Iter begin, Iter end);
		int shortestSpan(void) const;
		int longestSpan(void) const;
		// exception
		class NoFreeSpaceException : public std::exception
		{
			const char* what() const throw();
		};
		class NoSpanFoundException : public std::exception
		{
			const char* what() const throw();
		};
};

template <typename Iter>
void Span::addNumber(Iter begin, Iter end)
{
	if (std::distance(begin, end) + _data.size() > _max_size)
		throw (Span::NoFreeSpaceException());
	else
	{
		for(Iter i = begin; i != end; i++)
			_data.push_back(*i);
	}
}

#endif