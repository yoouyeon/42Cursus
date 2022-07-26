/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:07:17 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/26 15:50:51 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include <string>

# define P_SIGN_GRADE 25
# define P_EXEC_GRADE 5

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &origin);
	public:
		// constructor, canonical form
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm & operator=(const PresidentialPardonForm &origin);
		// accessor
		const std::string getTarget(void) const;
		// others
		void execute(Bureaucrat const & executor) const;
};

std::ostream &	operator<<(std::ostream &c, const PresidentialPardonForm &f);

#endif
