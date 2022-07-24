/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:03:11 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:37:15 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		// Constructors and Destructors, Canonical Form
		Animal(void);
		Animal(const Animal &origin);
		virtual ~Animal(void);
 		Animal &operator=(const Animal &origin);
		// Accessor
		std::string getType(void) const;
		// Others
		virtual void makeSound(void) const =0;
};

#endif
