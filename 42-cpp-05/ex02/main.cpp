/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:06:52 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:48 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardon.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Testing Forms Execution ===" << std::endl;

	try
	{
		std::cout << "\n--- Test 1: Successful Robotomy ---" << std::endl;
		Bureaucrat b1("Alice", 30);
		RobotomyRequestForm f1("John Doe");
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b1.executeForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 2: Presidential Pardon ---" << std::endl;
		Bureaucrat b2("Bob", 5);
		PresidentialPardon f2("Eve");
		std::cout << b2 << std::endl;
		std::cout << f2 << std::endl;
		b2.signForm(f2);
		std::cout << f2 << std::endl;
		b2.executeForm(f2);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 3: Shrubbery Creation ---" << std::endl;
		Bureaucrat b3("Charlie", 140);
		ShrubberyCreationForm f3("home");
		std::cout << b3 << std::endl;
		std::cout << f3 << std::endl;
		b3.signForm(f3);
		std::cout << f3 << std::endl;
		b3.executeForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 4: Not Signed Form ---" << std::endl;
		Bureaucrat b4("David", 5);
		PresidentialPardon f4("Frank");
		std::cout << b4 << std::endl;
		b4.executeForm(f4);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 5: Grade Too Low to Execute ---" << std::endl;
		Bureaucrat b5("Grace", 50);
		PresidentialPardon f5("Henry");
		std::cout << b5 << std::endl;
		b5.signForm(f5);
		b5.executeForm(f5);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
