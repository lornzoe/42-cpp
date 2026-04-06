/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:57 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:54 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <database.csv> <input.csv>\n";
		return 1;
	}
	BitcoinExchange b;
	b.loadDatabase(argv[1]);
	b.processInput(argv[2]);
	return 0;
}
