/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:27:46 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/22 19:06:33 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// constructor, canonical form
		ScavTrap(void);
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap(void);
		ScavTrap &operator =(const ScavTrap &src);
		// others
		void guardGate(void);
		void attack(const std::string& target);
};

#endif
