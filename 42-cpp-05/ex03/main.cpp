/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:08:11 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:50 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardon.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Testing Intern Form Factory ===" << std::endl;

	try
	{
		std::cout << "\n--- Test 1: Create Presidential Pardon Form ---" << std::endl;
		Intern intern;
		AForm *form1 = intern.makeForm("presidential pardon", "Alice");
		std::cout << *form1 << std::endl;
		delete form1;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 2: Create and Execute Robotomy Form ---" << std::endl;
		Intern intern;
		Bureaucrat b("Bob", 40);
		AForm *form2 = intern.makeForm("robotomy request", "John");
		std::cout << "Created: " << *form2 << std::endl;
		b.signForm(*form2);
		b.executeForm(*form2);
		delete form2;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 3: Create and Execute Shrubbery Creation Form ---" << std::endl;
		Intern intern;
		Bureaucrat c("Charlie", 140);
		AForm *form3 = intern.makeForm("shrubbery creation", "garden");
		std::cout << "Created: " << *form3 << std::endl;
		c.signForm(*form3);
		c.executeForm(*form3);
		delete form3;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 4: Unknown Form Type ---" << std::endl;
		Intern intern;
		AForm *form4 = intern.makeForm("invalid form", "target");
		delete form4;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Test 5: Presidential Pardon Execution ---" << std::endl;
		Intern intern;
		Bureaucrat d("David", 5);
		AForm *form5 = intern.makeForm("presidential pardon", "Eve");
		std::cout << "Created: " << *form5 << std::endl;
		d.signForm(*form5);
		d.executeForm(*form5);
		delete form5;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
