/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:26:51 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/11 13:47:36 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_first_name(void) const
{
	return (first_name_);
}

std::string Contact::get_last_name(void) const
{
	return (last_name_);
}

std::string Contact::get_nickname(void) const
{
	return (nickname_);
}

std::string Contact::get_phone_number(void) const
{
	return (phone_number_);
}

std::string Contact::get_darkest_secret(void) const
{
	return (darkest_secret_);
}

void Contact::set_first_name(std::string first_name)
{
	first_name_ = first_name;
}

void Contact::set_last_name(std::string last_name)
{
	last_name_ = last_name;
}

void Contact::set_nickname(std::string nickname)
{
	nickname_ = nickname;
}

void Contact::set_phone_number(std::string phone_number)
{
	phone_number_ = phone_number;
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
	darkest_secret_ = darkest_secret;
}
