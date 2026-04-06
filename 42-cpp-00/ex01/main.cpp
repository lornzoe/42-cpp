/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:44:13 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:29 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook book;
	std::string cmd;

	while (1)
	{
		std::cin.clear();
		std::cout << "Enter command: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break;
		if (cmd.compare("ADD") == 0)
			book.add();
		if (cmd.compare("SEARCH") == 0)
			book.search();
		if (cmd.compare("EXIT") == 0)
			break;
	}
	return (0);
}
