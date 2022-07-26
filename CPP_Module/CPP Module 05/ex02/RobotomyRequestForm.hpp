/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:07:13 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/26 15:50:51 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <string>

# define R_SIGN_GRADE 72
# define R_EXEC_GRADE 45

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &origin);
	public:
		// constructor, canonical form
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm & operator=(const RobotomyRequestForm &origin);
		// accessor
		const std::string getTarget(void) const;
		// others
		void execute(Bureaucrat const & executor) const;
};

std::ostream &	operator<<(std::ostream &c, const RobotomyRequestForm &f);

#endif
