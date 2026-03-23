/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:06:28 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:08:38 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Testing Bureaucrat and Form ===" << std::endl;

	try
	{
		std::cout << "\n--- Creating Valid Bureaucrat and Form ---" << std::endl;
		Bureaucrat b1("Alice", 50);
		Form f1("Salary Increase", 40, 30);
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;

		std::cout << "\n--- Bureaucrat Signing Form (Success) ---" << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;

		std::cout << "\n--- Bureaucrat Trying to Sign Form (Failure - Grade Too Low) ---" << std::endl;
		Bureaucrat b2("Bob", 60);
		Form f2("Promotion", 50, 40);
		std::cout << b2 << std::endl;
		std::cout << f2 << std::endl;
		b2.signForm(f2);

		std::cout << "\n--- Edge Case: Grade 1 (Highest) ---" << std::endl;
		Bureaucrat b3("Charlie", 1);
		Form f3("Important Order", 1, 1);
		std::cout << b3 << std::endl;
		std::cout << f3 << std::endl;
		b3.signForm(f3);

		std::cout << "\n--- Edge Case: Grade 150 (Lowest) ---" << std::endl;
		Bureaucrat b4("David", 150);
		Form f4("Routine Task", 150, 150);
		std::cout << b4 << std::endl;
		std::cout << f4 << std::endl;
		b4.signForm(f4);

		std::cout << "\n--- Creating Form with Invalid Grade (Too High) ---" << std::endl;
		Form f5("Invalid", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Creating Form with Invalid Grade (Too Low) ---" << std::endl;
		Form f6("Invalid", 50, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
