/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:55 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:18:24 by lyanga           ###   ########.fr       */
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
    void loadDatabase(const std::string &path);
    void processInput(const std::string &path);

private:
    std::map<std::string, double> rates;
    bool validDate(const std::string &date) const;
    bool parseLine(const std::string &line, std::string &date, double &value) const;
};

#endif // BITCOINEXCHANGE_HPP
