/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:07:57 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/10 11:26:03 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;
	public:
		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::string get_nickname(void) const;
		std::string get_phone_number(void) const;
		std::string get_darkest_secret(void) const;
		void set_first_name(std::string first_name);
		void set_last_name(std::string last_name);
		void set_nickname(std::string nickname);
		void set_phone_number(std::string phone_number);
		void set_darkest_secret(std::string darkest_secret);
};

#endif
