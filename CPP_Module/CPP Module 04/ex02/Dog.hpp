/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:05:09 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:37:15 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		// Constructors and Destructors, Canonical Form
		Dog(void);
		Dog(const Dog &origin);
		virtual ~Dog(void);
		Dog &operator= (const Dog &origin);
		// Accessor
		Brain *getBrain(void) const;
		// Others
		void makeSound(void) const;
};

#endif
