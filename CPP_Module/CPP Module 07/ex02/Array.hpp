/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 01:43:21 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/29 14:46:55 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *_array;
	public:
		// ANCHOR constructor, canonical form
		Array(void) : _size(0), _array(new T[0]) {}
		Array(unsigned int size) : _size(size), _array(new T[size]) {}
		Array(const Array &origin)
		{
			_size = origin.size();
			_array = new T[_size];
			for(unsigned int i = 0; i < _size; i++)
				_array[i] = origin[i];
		}
		Array<T> &operator =(const Array &origin)
		{
			if (this == &origin)
				return (*this);
			_size = origin.size();
			delete[] _array;
			_array = new T[_size];
			for(unsigned int i = 0; i < _size; i++)
				_array[i] = origin[i];
			return (*this);
		}
		~Array(void){delete[] _array;}
		// ANCHOR operator
		T &operator [](unsigned int idx)
		{
			if (idx >= _size)
				throw(std::exception());
			else
				return (_array[idx]);
		}
		const T &operator [](unsigned int idx) const
		{
			if (idx >= _size)
				throw(std::exception());
			else
				return (_array[idx]);
		}
		// ANCHOR accessor
		unsigned int size(void) const
		{
			return (_size);
		}
};

#endif