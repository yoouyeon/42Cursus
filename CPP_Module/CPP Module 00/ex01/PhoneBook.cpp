/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:36:49 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/11 02:39:28 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) : size_(0)
{
	std::cout << "=============================================\n";
	std::cout << "              Awesome PhoneBook              \n";
	std::cout << "=============================================\n";
	std::cout << "----------------- COMMANDS ------------------\n";
	std::cout << "[ADD] : save a new contact\n";
	std::cout << "[SEARCH] : display a specific contact\n";
	std::cout << "[EXIT] : The program quits\n";
	std::cout << "Any other input is discarded!!\n";
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::PrintContacts(void) const
{
	std::cout << "|------------ * Contact List * -------------|\n";
	std::cout << "|----------|----------|----------|----------|\n";
	std::cout << "|     index|first name| last name|  nickname|\n";
	std::cout << "|----------|----------|----------|----------|\n";
	for(int i = 0; i < size_; i++)
	{
		std::cout << '|' << std::setw(10) << i << '|';
		phonebookutils::FormattedPrint(contacts_[i].get_first_name());
		phonebookutils::FormattedPrint(contacts_[i].get_last_name());
		phonebookutils::FormattedPrint(contacts_[i].get_nickname());
		std::cout << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void PhoneBook::PrintContactDetails(int idx) const
{
	std::cout << " |-------------- * Details * ---------------|" << std::endl;
	std::cout << " | first name : " << contacts_[idx].get_first_name() << std::endl;
	std::cout << " | last name : " << contacts_[idx].get_last_name() << std::endl;
	std::cout << " | nickname : " << contacts_[idx].get_nickname() << std::endl;
	std::cout << " | phone number : " << contacts_[idx].get_phone_number() << std::endl;
	std::cout << " | darkest secret : " << contacts_[idx].get_darkest_secret() << std::endl;
	std::cout << " |------------------------------------------|" << std::endl;
}

void PhoneBook::Add(void)
{
	int idx;
	std::string input;
	if (size_ == 8)
	{
		for(int i = 0; i < 7; i++)
			contacts_[i] = contacts_[i + 1];
		idx = 7;
	}
	else
	{
		idx = size_;
		size_++;
	}
	phonebookutils::GetInputWithPrompt(" -> new first name : ", &input);
	contacts_[idx].set_first_name(input);
	phonebookutils::GetInputWithPrompt(" -> new last name : ", &input);
	contacts_[idx].set_last_name(input);
	phonebookutils::GetInputWithPrompt(" -> new nickname : ", &input);
	contacts_[idx].set_nickname(input);
	phonebookutils::GetInputWithPrompt(" -> new phone number : ", &input);
	contacts_[idx].set_phone_number(input);
	phonebookutils::GetInputWithPrompt(" -> new darkest secret : ", &input);
	contacts_[idx].set_darkest_secret(input);
	std::cout << "[*] Successfully added new contact." << std::endl;
}

void PhoneBook::Search(void) const
{
	int idx;
	if (size_ == 0)
		std::cout << "[!] PhoneBook is empty." << std::endl;
	else
	{
		PrintContacts();
		phonebookutils::GetInputWithPrompt(" -> target index (0 ~ 7) : ", &idx);
		if (idx >= size_)
			std::cout << "Error : The maximum index is " << size_ - 1 << std::endl;
		else
			PrintContactDetails(idx);
	}
}
