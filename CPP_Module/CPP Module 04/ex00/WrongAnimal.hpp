/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:05:23 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:34:45 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		// Constructors and Destructors, Canonical Form
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &origin);
		~WrongAnimal(void);
 		WrongAnimal &operator=(const WrongAnimal &origin);
		// Accessor
		std::string getType(void) const;
		// Others
		void makeSound(void) const;
};

#endif
