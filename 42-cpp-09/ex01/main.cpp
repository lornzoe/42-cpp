/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:18:02 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/23 12:43:08 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"RPN expression\"\n";
		return 1;
	}
	try
	{
		double res = RPN::evaluate(argv[1]);
		std::cout << std::endl << res << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
