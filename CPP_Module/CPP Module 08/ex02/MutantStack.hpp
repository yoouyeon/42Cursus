/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:16:32 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/31 16:01:47 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator		iterator;
		// canonical form
		MutantStack(void) { }
		MutantStack(const MutantStack &origin) { *this = origin; }
		~MutantStack(void) { }
		MutantStack &operator =(const MutantStack &origin)
		{
			if (this != &origin)
				std::stack<T>::operator=(origin);
			return (*this);
		}
		// make iterable
		iterator begin(void) { return (this->c.begin());}
		iterator end(void) { return (this->c.end()); }
};

#endif