/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:06:09 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:08:38 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Testing Bureaucrat ===" << std::endl;

	try
	{
		std::cout << "\n--- Creating Valid Bureaucrat ---" << std::endl;
		Bureaucrat b1("Alice", 50);
		std::cout << b1 << std::endl;

		std::cout << "\n--- Testing Increment ---" << std::endl;
		b1.incrementGrade();
		std::cout << "After increment: " << b1 << std::endl;

		std::cout << "\n--- Testing Decrement ---" << std::endl;
		b1.decrementGrade();
		b1.decrementGrade();
		std::cout << "After 2 decrements: " << b1 << std::endl;

		std::cout << "\n--- Testing Grade Too High ---" << std::endl;
		Bureaucrat b2("Bob", 1);
		std::cout << b2 << std::endl;
		b2.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Testing Grade Too Low ---" << std::endl;
		Bureaucrat b3("Charlie", 150);
		std::cout << b3 << std::endl;
		b3.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Testing Invalid Grade at Construction (Too High) ---" << std::endl;
		Bureaucrat b4("David", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Testing Invalid Grade at Construction (Too Low) ---" << std::endl;
		Bureaucrat b5("Eve", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Testing Copy Constructor and Assignment ---" << std::endl;
		Bureaucrat b6("Frank", 75);
		Bureaucrat b7 = b6;
		std::cout << "Original: " << b6 << std::endl;
		std::cout << "Copy: " << b7 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
