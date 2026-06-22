/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:42 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/22 18:41:24 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

static bool isLeap(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static void stripWhitespacePadding(std::string &value)
{
	while (!value.empty() && std::isspace(*(value.begin())))
		value.erase(0,1);
	while (!value.empty() && std::isspace(*(value.end()-1)))
		value.erase(value.size()-1,1);
}

bool BitcoinExchange::validDate(const std::string &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int y, m, d;
	if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3)
		return false;
	if (m < 1 || m > 12 || d < 1)
		return false;
	int mdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (m == 2 && isLeap(y))
		mdays[2] = 29;
	if (d > mdays[m])
		return false;
	return true;
}

void BitcoinExchange::processDatabaseLine(const std::string &line)
{
	std::stringstream ss(line);
	std::string date, rate;
	if (!std::getline(ss, date, ',') || !std::getline(ss, rate))
	{
		std::cerr << "Error: bad data => " << line << std::endl;
		return;
	}
	if (!validDate(date))
	{
		std::cerr << "Error: bad date => " << line << std::endl;
		return;
	}
	// check if rate is a clean value
	char *end;
	double value = strtod(rate.c_str(), &end);
	if (*end != '\0')
	{
		std::cerr << "Error: bad value => " << line << std::endl;
		return;
	}
	rates[date] = value;
}

void BitcoinExchange::loadDatabase() {
	std::cout << "=== loadDatabase() // loading data.csv" << std::endl;
	std::ifstream f;
	f.open("data.csv");
	if (!f.is_open()) {
		std::cerr << "Error: cannot open database file (looking for: data.csv)" << std::endl;
		exit(1);
	}
	try
	{
		std::string line;
		// header 
		std::getline(f, line);
		// do header check
		if (!line.empty())
		{
			std::stringstream ss(line);
			std::string date, rate;
			if (!std::getline(ss, date, ',') || !std::getline(ss, rate))
			{
				std::cerr << "Error: invalid first/header row" << std::endl;
			}
			else
			{
				stripWhitespacePadding(date);
				stripWhitespacePadding(rate);
				if (date == "date" && rate == "exchange_rate")
				{
					std::cout << "=== [date,exchange_rate] header detected, moving on to next row" << std::endl;
				}
				else
					processDatabaseLine(line);
			}
		}
		// file contents
		while (std::getline(f, line)) {
			if (line.empty())
				continue;
			processDatabaseLine(line);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	f.close();
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &date, double &value) const {
	std::string token;
	std::stringstream ss(line);
	if (!std::getline(ss, date, '|'))
		return false;
	if (!std::getline(ss, token))
		return false;

	// trim spaces
	stripWhitespacePadding(date);
	stripWhitespacePadding(token);

	if (date.empty() || token.empty())
		return false;
	if (!validDate(date)) 
		return false;

	char *end;
	value = strtod(token.c_str(), &end);
	if (*end != '\0')
		return false;
	if (value < 0 || value > 1000)
	{
		std::cerr << "Error: bad input => " << value << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::processInputLine(const std::string &line)
{
	std::string date;
	double value;
	if (!parseLine(line, date, value)) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	std::map<std::string,double>::const_iterator it = rates.lower_bound(date);
	if (it == rates.end() || it->first != date) {
		if (it == rates.begin()) {
			std::cerr << "Error: no rate available for date " << date << std::endl;
			return;
		}
		--it;
	}
	double result = value * it->second;
	std::cout << "[" << it->first << " | " << it->second << "] "; // reference the value used
	std::cout << date << " => " << value << " = " << result << std::endl;
	return;
}

void BitcoinExchange::processInput(const std::string &path) {
	std::cout << "=== processInput(" << path << ")" << std::endl;
	std::ifstream f;
	f.open(path.c_str());
	if (!f.is_open()) {
		std::cerr << "Error: cannot open input file" << std::endl;
		exit(1);
	}
	
	std::string line;
	std::getline(f, line); // header
	// header check
	if (!line.empty())
	{
		std::stringstream ss(line);
		std::string date, value;
		if (!std::getline(ss, date, '|') || !std::getline(ss, value))
		{
			std::cerr << "Error: invalid first/header row" << std::endl;
		}
		else
		{
			// strip whitespaces
			stripWhitespacePadding(date);
			stripWhitespacePadding(value);

			// std::cout << "date: [" << date << "], value: [" << value << "]" << std::endl;
			if (date == "date" && value == "value")
			{
				std::cout << "=== [date | value] header detected, moving on to next row" << std::endl;
			}
			else 
				processInputLine(line);
		}
	}

	// content
	while (std::getline(f, line)) {
		if (line.empty())
			continue;
		processInputLine(line);
	}
	f.close();
}
