/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 00:15:28 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/28 15:34:11 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serialization.hpp"

int main(void)
{
	Data info;

	info.name = "Peter Parker";
	info.age = 20;
	info.nickname = "Spider-Man";

	uintptr_t serialized = serialize(&info);
	Data *deserialized = deserialize(serialized);

	std::cout << "------------ original Data ------------" << std::endl;
	std::cout << "name : " << info.name << std::endl;
	std::cout << "age : " << info.age << std::endl;
	std::cout << "nickname : " << info.nickname << std::endl;
	std::cout << "address : " << &info << std::endl;

	std::cout << "\n------------ Serialization ------------" << std::endl;
	std::cout << "serialized : " << serialized << std::endl;
	std::cout << "deserialized : " << deserialized << std::endl;
	std::cout << "name : " << deserialized->name << std::endl;
	std::cout << "age : " << deserialized->age << std::endl;
	std::cout << "nickname : " << deserialized->nickname << std::endl;
	
	return (0);
}