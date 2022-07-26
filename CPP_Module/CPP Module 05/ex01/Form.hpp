/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 01:42:41 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/26 15:50:51 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _required_sign_grade;
		const int _required_exec_grade;
	public:
		// constructor, canonical form
		Form(void);
		Form(const std::string name, const int required_sign_grade, const int required_exec_grade);
		Form(const Form &origin);
		~Form(void);
		Form &operator= (const Form &origin);
		// accessor
		std::string getName(void) const;
		bool isSigned(void) const;
		int getRequiredSignGrade(void) const;
		int getRequiredExecGrade(void) const;
		// others
		void beSigned(const Bureaucrat &b);
		// exception
		class GradeTooHighException : public std::exception
		{
			public :
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char * what() const throw();
		};
};

std::ostream &	operator<<(std::ostream &c, const Form &f);

#endif
