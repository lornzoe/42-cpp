/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:55 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/23 12:54:48 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	
	void loadDatabase();
	void processInput(const std::string &path);

private:
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	
	std::map<std::string, double> rates;

	// helper functions
	bool validDate(const std::string &date) const;
	bool parseLine(const std::string &line, std::string &date, double &value) const;
	void processDatabaseLine(const std::string &line);
	void processInputLine(const std::string &line);
};

#endif // BITCOINEXCHANGE_HPP
