/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:03:36 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:36:15 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		// Constructors and Destructors, Canonical Form
		Cat(void);
		Cat(const Cat &origin);
		virtual ~Cat(void);
		Cat &operator=(const Cat &origin);
		// Accessor
		Brain *getBrain(void) const;
		// Others
		void makeSound(void) const;
};

#endif
