/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:06:09 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/07 16:18:37 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try
	{
		std::cout << std::endl << "--- valid bureaucrat ---" << std::endl;
		Bureaucrat b1("alice", 50);
		std::cout << b1 << std::endl;

		std::cout << std::endl << "--- test increment ---" << std::endl;
		b1.incrementGrade();
		std::cout << "After increment: " << b1 << std::endl;

		std::cout << std::endl << "--- test decrement ---" << std::endl;
		b1.decrementGrade();
		b1.decrementGrade();
		std::cout << "After 2 decrements: " << b1 << std::endl;

		std::cout << std::endl << "--- testing grade too high ---" << std::endl;
		Bureaucrat b2("bob", 1);
		std::cout << b2 << std::endl;
		b2.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "--- testing grade too low ---" << std::endl;
		Bureaucrat b3("bobby", 150);
		std::cout << b3 << std::endl;
		b3.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "--- testing invalid grade on constructor (grade 0, too high) ---" << std::endl;
		Bureaucrat b4("berb", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "--- testing invalid grade on constructor (grade 151, too low) ---" << std::endl;
		Bureaucrat b5("ben", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "--- testing copy constructor and assignment ---" << std::endl;
		Bureaucrat b6("bertha", 75);
		Bureaucrat b7 = b6;
		std::cout << "Original: " << b6 << std::endl;
		b6.decrementGrade();
		std::cout << "Original decrementGrade(): " << b6 << std::endl;
		std::cout << "Copy: " << b7 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
