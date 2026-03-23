/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:42 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:18:24 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

static bool isLeap(int year) { return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); }

bool BitcoinExchange::validDate(const std::string &date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
    int y, m, d;
    if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3) return false;
    if (m < 1 || m > 12 || d < 1) return false;
    int mdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeap(y)) mdays[2] = 29;
    if (d > mdays[m]) return false;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string &path) {
    std::ifstream f(path.c_str());
    if (!f.is_open()) {
        std::cerr << "Error: cannot open database file\n";
        exit(1);
    }
    std::string line;
    std::getline(f, line); // header
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string date, rate;
        if (!std::getline(ss, date, ',') || !std::getline(ss, rate)) continue;
        if (!validDate(date)) continue;
        double v = atof(rate.c_str());
        rates[date] = v;
    }
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &date, double &value) const {
    std::string token;
    std::stringstream ss(line);
    if (!std::getline(ss, date, '|')) return false;
    if (!std::getline(ss, token)) return false;
    // trim spaces
    while (!date.empty() && (date[date.size()-1] == ' ' || date[date.size()-1] == '\t')) date.erase(date.size()-1,1);
    while (!date.empty() && (date[0] == ' ' || date[0] == '\t')) date.erase(0,1);
    while (!token.empty() && (token[0] == ' ' || token[0] == '\t')) token.erase(0,1);
    while (!token.empty() && (token[token.size()-1] == ' ' || token[token.size()-1] == '\t')) token.erase(token.size()-1,1);
    if (date.empty() || token.empty()) return false;
    if (!validDate(date)) return false;
    char *end;
    value = strtod(token.c_str(), &end);
    if (*end != '\0') return false;
    if (value < 0 || value > 1000) {
        std::cerr << "Error: bad input => " << value << "\n";
        return false;
    }
    return true;
}

void BitcoinExchange::processInput(const std::string &path) {
    std::ifstream f(path.c_str());
    if (!f.is_open()) {
        std::cerr << "Error: cannot open input file\n";
        exit(1);
    }
    std::string line;
    std::getline(f, line); // header
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        std::string date;
        double value;
        if (!parseLine(line, date, value)) {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }
        std::map<std::string,double>::const_iterator it = rates.lower_bound(date);
        if (it == rates.end() || it->first != date) {
            if (it == rates.begin()) {
                std::cerr << "Error: no rate available for date " << date << "\n";
                continue;
            }
            --it;
        }
        double result = value * it->second;
        std::cout << date << " => " << value << " = " << result << "\n";
    }
}
