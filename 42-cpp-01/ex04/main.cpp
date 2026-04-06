/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:51:00 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:43:21 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replace(std::string& str, const std::string& from, const std::string& to)
{
	if (from.empty())
		return;
	size_t start_pos = 0;
	start_pos = str.find(from, start_pos);
	while ((start_pos) != std::string::npos)
	{
		str.erase(start_pos, from.length());
		str.insert(start_pos, to);
		start_pos += to.length();
		start_pos = str.find(from, start_pos);
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./ex04 <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return 1;
	}

	std::ofstream ofs((filename + ".replace").c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Error: could not create file " << filename << ".replace" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(ifs, line))
	{
		replace(line, s1, s2);
		ofs << line << std::endl;
	}

	ifs.close();
	ofs.close();

	return 0;
}
