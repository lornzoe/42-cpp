/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:17 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/16 14:48:01 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main() {
	srand(time(NULL));

	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;

	try {
		sp.addNumber(100);
	} catch (const std::exception &e) {
		std::cout << "expected full: " << e.what() << std::endl;
	}

	Span sp2(10000);
	for (int i = 0; i < 10000; ++i)
	{
		sp2.addNumber(i * (rand() % 10));
	}
	std::cout << "shortest: " << sp2.shortestSpan() << std::endl;
	std::cout << "longest: " << sp2.longestSpan() << std::endl;

	return 0;
}
