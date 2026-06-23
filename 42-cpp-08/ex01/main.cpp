/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:17 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/23 21:42:05 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>

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

	Span sp3(100);
	std::list<int> v3;
	for (int i = 0; i < 100; i++)
	{
		v3.push_back(i);
	}
	try
	{
		sp3.addNumber(v3.begin(), v3.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "shortest: " << sp3.shortestSpan() << std::endl;
	std::cout << "longest: " << sp3.longestSpan() << std::endl;

	// Span sp4(20);
	// std::vector<int> v4;
	// std::vector<int> v42;
	// for (int i = 10; i < 20; i++)
	// {
	// 	v4.push_back(i);
	// }
	// v42.push_back(999);
	// try
	// {
	// 	sp4.addNumber(v4.begin(), v42.end());
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }
	

	return 0;
}
