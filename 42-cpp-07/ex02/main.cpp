/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:12:53 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/26 17:19:08 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

// from provided main file
#include <cstdlib>
#define MAX_VAL 750 

int main() {
	{
		Array<int> a(5);
		std::cout << "a size: " << a.size() << std::endl;
		for (std::size_t i = 0; i < a.size(); ++i)
			a[i] = i * 10;

		for (std::size_t i = 0; i < a.size(); ++i)
			std::cout << a[i] << " ";
		std::cout << std::endl;

		Array<int> b = a;
		b[0] = 42;
		std::cout << "a[0]=" << a[0] << " b[0]=" << b[0] << std::endl;

		// out of bounds access
		try {
			a[10] = 1;
		} catch (const std::exception &e) {
			std::cout << "caught: " << e.what() << std::endl;
		}
	}
	// from provided main file
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	return 0;
}
