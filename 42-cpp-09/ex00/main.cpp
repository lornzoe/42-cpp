/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:57 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/22 14:09:39 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input.csv>\n";
		return 1;
	}
	BitcoinExchange b;
	b.loadDatabase();
	std::cout << "== Successfully loaded data.csv, now processing input file." << std::endl;
	b.processInput(argv[1]);
	std::cout << "== done." << std::endl;
	return 0;
}
