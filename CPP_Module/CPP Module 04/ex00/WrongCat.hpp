/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:05:42 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:34:51 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructors and Destructors, Canonical Form
		WrongCat(void);
		WrongCat(const WrongCat &origin);
		~WrongCat(void);
		WrongCat &operator=(const WrongCat &origin);
		// Others
		void makeSound(void) const;
};

#endif
