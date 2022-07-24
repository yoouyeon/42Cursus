/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:34:44 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/24 15:37:15 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		// Constructors and Destructors, Canonical Form
		Brain(void);
		Brain(const Brain &origin);
		~Brain(void);
		Brain &operator= (const Brain &origin);
		// Accessor
		std::string getIdea(int idx) const;
		void setIdea(int idx, std::string idea);
};

#endif
