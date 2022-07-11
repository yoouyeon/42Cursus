/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:36:47 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/11 13:47:20 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		int size_;
		Contact contacts_[8];
		void PrintContacts(void) const;
		void PrintContactDetails(int idx) const;

	public:
		void Add(void);
		void Search(void) const;
		PhoneBook(void);
};

#endif
