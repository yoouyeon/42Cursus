/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:06:18 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/26 15:16:54 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "Form.hpp"

# define S_SIGN_GRADE 145
# define S_EXEC_GRADE 137

class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &origin);
	public:
		// constructor, canonical form
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &origin);
		// accessor
		const std::string getTarget(void) const;
		// others
		void execute(Bureaucrat const & executor) const;
};

std::ostream &	operator<<(std::ostream &c, const ShrubberyCreationForm &f);

#endif
