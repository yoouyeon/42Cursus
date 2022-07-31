/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 20:16:53 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/31 02:28:11 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

#define UCYAN "\x1b[4;36m"
#define CYAN "\x1b[0;36m"
#define RESET "\x1b[0m"

int main(void)
{
	int test_arr[5] = {1, 6, 3, 78, 8};
	{
		std::cout << UCYAN << "========= vector =========" << RESET << std::endl;
		std::vector<int> test(test_arr, test_arr + 5);
		std::vector<int>::iterator iter;
		iter = easyfind(test, 78);
		if (iter == test.end())
			std::cout << "NOT FOUND" << std::endl;
		else
			std::cout << *iter << " is in test container" << std::endl;
		iter = easyfind(test, 100);
		if (iter == test.end())
			std::cout << "NOT FOUND" << std::endl;
		else
			std::cout << *iter << " is in test container" << std::endl;
	}
	{
		std::cout << UCYAN << "========== list ==========" << RESET << std::endl;
		std::list<int> test(test_arr, test_arr + 5);
		std::list<int>::iterator iter;
		iter = easyfind(test, 6);
		if (iter == test.end())
			std::cout << "NOT FOUND" << std::endl;
		else
			std::cout << *iter << " is in test container" << std::endl;
		iter = easyfind(test, 0);
		if (iter == test.end())
			std::cout << "NOT FOUND" << std::endl;
		else
			std::cout << *iter << " is in test container" << std::endl;
	}
	return(0);
}
