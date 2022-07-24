/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:34:42 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:13:52 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"
// ANCHOR Constructors and Destructors, Canonical Form
Brain::Brain(void)
{
	std::cout << "[Brain] Default constructor" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain &origin)
{
	std::cout << "[Brain] Copy constructor" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = origin.getIdea(i);
}

Brain::~Brain(void)
{
	std::cout << "[Brain] Default destructor" << std::endl;
}

Brain &Brain::operator= (const Brain &origin)
{
	std::cout << "[Brain] Copy assignment operator" << std::endl;
	if (this != &origin)
	{
		for(int i = 0; i < 100; i++)
			ideas[i] = origin.getIdea(i);
	}
	return (*this);
}

// ANCHOR Accessor
std::string Brain::getIdea(int idx) const
{
	if (idx > 99 || idx < 0)
	{
		std::cout << "Error : index (0 ~ 99)" << std::endl;
		return ("");
	}
	return (ideas[idx]);
}

void Brain::setIdea(int idx, std::string idea)
{
	if (idx > 99 || idx < 0)
	{
		std::cout << "Error : index (0 ~ 99)" << std::endl;
		return ;
	}
	ideas[idx] = idea;
}
