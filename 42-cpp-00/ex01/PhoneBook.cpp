/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:26:36 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/17 19:01:31 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

PhoneBook::PhoneBook()
{
	highestIndex = -1;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add()
{
	std::string first, last, nick, num, secret;
	std::string input = "";

	while (input.empty())
	{
		std::cin.clear();
		std::cout << "Enter the contact's first name: ";
		std::getline(std::cin, input);
		if (!input.empty())
			break;
		std::cout << "Empty fields not allowed." << std::endl;
	}
	first = input;
	input = "";

	while (input.empty())
	{
		std::cin.clear();
		std::cout << "Enter the contact's last name: ";
		std::getline(std::cin, input);
		if (!input.empty())
			break;
		std::cout << "Empty fields not allowed." << std::endl;
	}
	last = input;
	input = "";

	while (input.empty())
	{
		std::cin.clear();
		std::cout << "Enter the contact's nickname: ";
		std::getline(std::cin, input);
		if (!input.empty())
			break;
		std::cout << "Empty fields not allowed." << std::endl;
	}
	nick = input;
	input = "";

	while (input.empty())
	{
		std::cin.clear();
		std::cout << "Enter the contact's number: ";
		std::getline(std::cin, input);
		if (!input.empty())
			break;
		std::cout << "Empty fields not allowed." << std::endl;
	}
	num = input;
	input = "";

	while (input.empty())
	{
		std::cin.clear();
		std::cout << "Enter the contact's darkest secret: ";
		std::getline(std::cin, input);
		if (!input.empty())
			break;
		std::cout << "Empty fields not allowed." << std::endl;
	}
	secret = input;
	input = "";

	int indexToUse = highestIndex % 8 + 1;
	contacts[indexToUse] = Contact(indexToUse, first, last, nick, num, secret);
	highestIndex++;
	if (highestIndex >= 8)
		std::cout << "There are more than 8 contacts, the oldest contact will be replaced." << std::endl;
}

static void printTruncated(std::string str)
{
	if (str.length() > 10)
		std::cout << std::setw(10) << str.substr(0, 7) + "...";
	else
		std::cout << std::setw(10) << str;
}

void PhoneBook::search()
{
	if (highestIndex == -1)
	{
		std::cout << "There's no contacts to search." << std::endl;
		return;
	}

	// Displaying table of contacts
	for (int i = 0; i < 45; i++)
		std::cout << '-';
	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
	{
		if (i > highestIndex)
			break;
		std::cout << "|";
		std::cout << std::setw(10) << i;
		std::cout << "|";
		printTruncated(contacts[i].getFirstName());
		std::cout << "|";
		printTruncated(contacts[i].getLastName());
		std::cout << "|";
		printTruncated(contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
	for (int i = 0; i < 45; i++)
		std::cout << '-';
	std::cout << std::endl;

	// User prompt
	std::string input;
	while (1)
	{
		std::cout << "Enter the index of the entry to display: ";
		std::cin.clear();
		std::getline(std::cin, input);
		
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
		{
			int index = std::atoi(input.c_str());

			if (highestIndex >= index)
			{
				std::cout << "Contact found:\n";
				std::cout << "	First name: " << contacts[index].getFirstName() << std::endl;
				std::cout << "	Last name: " << contacts[index].getLastName() << std::endl;
				std::cout << "	Nickname: " << contacts[index].getNickname() << std::endl;
				std::cout << "	Phone number: " << contacts[index].getNumber() << std::endl;
				std::cout << "	Darkest secret: " << contacts[index].getSecret() << std::endl;
				break;
			}
		}
		std::cout << "Invalid input." << std::endl;
	}
}
