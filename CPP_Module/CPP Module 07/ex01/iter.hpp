/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:35:56 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/29 13:29:24 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *arr, unsigned int size, void (*func)(const T &))
{
	if (func == NULL)
		return;
	for (unsigned int i = 0 ; i < size ; i++)
		func(arr[i]);
}

template <typename T>
void iter(T *arr, unsigned int size, void (*func)(T &))
{
	if (func == NULL)
		return;
	for (unsigned int i = 0 ; i < size ; i++)
		func(arr[i]);
}

#endif
