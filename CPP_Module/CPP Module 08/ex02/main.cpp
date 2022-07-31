/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:16:37 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/31 16:23:42 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include "MutantStack.hpp"

#define RED "\x1b[0;31m"
#define UCYAN "\x1b[4;36m"
#define CYAN "\x1b[0;36m"
#define RESET "\x1b[0m"

template <typename Iter>
void printInside(Iter begin, Iter end)
{
	std::cout << "---- print inside ----" << std::endl;
	Iter iter= begin;
	while (iter != end)
		std::cout << *iter++ << std::endl;
	std::cout << "----------------------" << std::endl;
}


int main()
{
	{
		std::cout << UCYAN << "================= Vector Test ================" << RESET << std::endl;
		std::vector<int> vstack;
		vstack.push_back(5);
		vstack.push_back(17);
		std::cout << "current top(back) : " << vstack.back() << " current size : " << vstack.size() << std::endl;
		vstack.pop_back();
		std::cout << "current top(back) : " << vstack.back() << " current size : " << vstack.size() << std::endl;
		vstack.push_back(3);
		vstack.push_back(5);
		vstack.push_back(737);
		vstack.push_back(0);
		std::vector<int>::iterator it = vstack.begin();
		std::vector<int>::iterator ite = vstack.end();
		++it;
		--it;
		printInside(it, ite);
	}
	{
		std::cout << UCYAN << "\n================= MStack Test ================" << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "current top : " << mstack.top() << " current size : " << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "current top : " << mstack.top() << " current size : " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << CYAN << "------ before -------" << RESET << std::endl;
		printInside(it, ite);
		it = mstack.begin();
		ite = mstack.end();
		*it = 1;
		std::cout << CYAN << "------- after -------" << RESET << std::endl;
		printInside(it, ite);
	}
	{
		std::cout << UCYAN << "================= use iter Test ================" << RESET << std::endl;
		MutantStack<std::string> mstack;
		mstack.push("CPP 08");
		mstack.push("CPP 07");
		mstack.push("CPP 02");
		mstack.push("CPP 03");
		mstack.push("CPP 01");
		mstack.push("CPP 04");
		mstack.push("CPP 06");
		mstack.push("CPP 05");
		mstack.push("CPP 00");
		printInside(mstack.begin(), mstack.end());
		std::cout << CYAN << "---- find CPP 09 ----" << RESET << std::endl;
		if (std::find(mstack.begin(), mstack.end(), "CPP 09") == mstack.end())
			std::cout << "CPP 09 is not in mstack" << std::endl;
		else
			std::cout << "CPP 09 is in mstack" << std::endl;
		std::cout << CYAN << "---- find CPP 08 ----" << RESET << std::endl;
		if (std::find(mstack.begin(), mstack.end(), "CPP 08") == mstack.end())
			std::cout << "CPP 08 is not in mstack" << std::endl;
		else
			std::cout << "CPP 08 is in mstack" << std::endl;
		std::cout << CYAN << "------- sort --------" << RESET << std::endl;
		sort(mstack.begin(), mstack.end());
		printInside(mstack.begin(), mstack.end());
	}
	return 0;
}