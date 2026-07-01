/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:17 by lyanga            #+#    #+#             */
/*   Updated: 2026/07/02 01:40:05 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <ctime>
#include <limits>

int main() {
	srand(time(NULL));

	std::cout << "1=============================" << std::endl;
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

	std::cout << "2=============================" << std::endl;
	Span sp2(10000);
	for (int i = 0; i < 10000; ++i)
	{
		sp2.addNumber(i * (rand() % 10));
	}
	std::cout << "shortest: " << sp2.shortestSpan() << std::endl;
	std::cout << "longest: " << sp2.longestSpan() << std::endl;

	std::cout << "3=============================" << std::endl;
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
	
	// std::cout << "4=============================" << std::endl;
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
	// try
	// {
	// 	std::cout << "shortest: " << sp4.shortestSpan() << std::endl;
	// 	std::cout << "longest: " << sp4.longestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }

	std::cout << "5=============================" << std::endl;
	Span sp5(2);
	sp5.addNumber(std::numeric_limits<int>::max());
	sp5.addNumber(std::numeric_limits<int>::min());
	try
	{
		std::cout << "shortest: " << sp5.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp5.longestSpan() << std::endl;
		std::cout << "check:    " << static_cast<unsigned long>(std::numeric_limits<int>::max()) - std::numeric_limits<int>::min() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "6=============================" << std::endl;
	Span sp6(5);
	try	
	{
		std::cout << sp6.shortestSpan() << std::endl; // Empty
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected error (empty): " << e.what() << std::endl;
	}

	sp6.addNumber(42);
	try
	{
		std::cout << sp6.longestSpan() << std::endl; // Only 1 element
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected error (1 element): " << e.what() << std::endl;
	}

	std::cout << "7=============================" << std::endl;
	Span sp7(5);
	sp7.addNumber(10);
	sp7.addNumber(20);
	sp7.addNumber(10);
	sp7.addNumber(30);

	std::cout << "Shortest (should be 0): " << sp7.shortestSpan() << std::endl;
	std::cout << "Longest (should be 20): " << sp7.longestSpan() << std::endl;

	std::cout << "8=============================" << std::endl;
	Span sp8(4);
	sp8.addNumber(-20);
	sp8.addNumber(-10);
	sp8.addNumber(-5);
	sp8.addNumber(-1);

	std::cout << "Shortest (should be 4): " << sp8.shortestSpan() << std::endl; // (-1 - (-5))
	std::cout << "Longest (should be 19): " << sp8.longestSpan() << std::endl;  // (-1 - (-20))

	return 0;
}
