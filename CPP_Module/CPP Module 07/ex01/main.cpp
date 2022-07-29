/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 03:35:52 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/29 14:54:13 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void increase(int &a)
{
	a++;
}

void decrease(int &b)
{
	b--;
}

template <typename T>
void print(T const &element)
{
	std::cout << element << std::endl;
}

int main(void)
{
	char char_arr[5] = {'a', 'B', 'c', 'D', '2'};
	int	int_arr[5] = {1, 2, 3, 4, -1};
	std::string str_arr[5] = {"CPP Module 00", "CPP Module 01", "CPP Module 02", "CPP Module 03", "CPP Module 04"};

	std::cout << "====== char ======" << std::endl;
	iter(char_arr, 5, print);
	std::cout << "\n===== string =====" << std::endl;
	iter(str_arr, 5, print);
	std::cout << "\n======= int ======" << std::endl;
	iter(int_arr, 5, print);
	std::cout << "\n--- increase ---" << std::endl;
	iter(int_arr, 5, increase);
	iter(int_arr, 5, print);
	std::cout << "\n--- decrease ---" << std::endl;
	iter(int_arr, 5, decrease);
	iter(int_arr, 5, print);

	return (0);
}
