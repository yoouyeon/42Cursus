/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:54:31 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/28 16:50:43 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int option = rand() % 3;

	switch(option)
	{
		case 0:
		{
			std::cout << "Generate Class A" << std::endl;
			return new A();
			break;
		}
		case 1:
		{
			std::cout << "Generate Class B" << std::endl;
			return new B();
			break;
		}
		default:
		{
			std::cout << "Generate Class C" << std::endl;
			return new C();
			break;
		}
	}
}

void identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);
	if (a)
		std::cout << "this is class A" << std::endl;
	else if (b)
		std::cout << "this is class B" << std::endl;
	else if (c)
		std::cout << "this is class C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "this is class A" << std::endl;
		static_cast<void>(a);
		return ;
	}
	catch(std::exception& e) { }
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "this is class B" << std::endl;
		static_cast<void>(b);
		return ;
	}
	catch(std::exception& e) {}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "this is class C" << std::endl;
		static_cast<void>(c);
		return ;
	}
	catch(std::exception& e) {}
}

int main(void)
{
	srand(time(NULL));

	for(int i = 0; i < 5; i++)
	{
		Base *unknown_class = generate();
		identify(unknown_class);
		identify(*unknown_class);
		std::cout << "\n";
		delete unknown_class;
	}

	return (0);
}