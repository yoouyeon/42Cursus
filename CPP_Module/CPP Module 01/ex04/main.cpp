/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:30:49 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/16 16:09:38 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage : ./ex04 filename s1 s2" << std::endl;
		return (0);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cout << "ERROR : Empty Argument" << std::endl;
		return (0);
	}
	// ANCHOR file open
	std::ifstream ifs(filename);
	if (!ifs.good())
	{
		std::cout << "Error : Unable to open file for reading." << std::endl;
		return (0);
	}
	std::ofstream ofs(filename + ".replace", std::ios_base::out | std::ios_base::trunc);
	if (!ofs.good())
	{
		std::cout << "Error : Unable to open file for writing." << std::endl;
		ifs.close();
		return (0);
	}

	// ANCHOR file read
	std::string input_str;
	std::string file_str = "";
	size_t idx = 0;
	while (1)
	{
		std::getline(ifs, input_str);
		if (ifs.eof())
		{
			file_str += input_str;
			break;
		}
		if (ifs.fail() || ifs.bad())
		{
			std::cout << "Error : File read." << std::endl;
			ifs.close();
			ofs.close();
			return (0);
		}
		file_str += input_str;
		file_str += "\n";
	}
	// ANCHOR sed
	while (1)
	{
		idx = file_str.find(s1, idx);
		if (idx == std::string::npos)
		{
			ofs << file_str;
			break;
		}
		file_str.erase(idx, s1.length());
		file_str.insert(idx, s2);
		idx += s2.length();
	}
	ifs.close();
	ofs.close();
	return (0);
}
