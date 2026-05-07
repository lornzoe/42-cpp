/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:06:28 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/07 16:24:36 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	try
	{
		std::cout << "\n--- valid bureaucrat and form ---" << std::endl;
		Bureaucrat b1("alice", 50);
		Form f1("form 1", 40, 30);
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;

		std::cout << "\n--- bureaucrat signForm() (success) ---" << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;

		std::cout << "\n--- bureaucrat signForm() (fail - grade too low) ---" << std::endl;
		Bureaucrat b2("bob", 60);
		Form f2("form 2", 50, 40);
		std::cout << b2 << std::endl;
		std::cout << f2 << std::endl;
		b2.signForm(f2);

		std::cout << "\n--- highest grade case ---" << std::endl;
		Bureaucrat b3("benny", 1);
		Form f3("grade1form", 1, 1);
		std::cout << b3 << std::endl;
		std::cout << f3 << std::endl;
		b3.signForm(f3);

		std::cout << "\n--- lowest grade case ---" << std::endl;
		Bureaucrat b4("ben", 150);
		Form f4("grade150form", 150, 150);
		std::cout << b4 << std::endl;
		std::cout << f4 << std::endl;
		b4.signForm(f4);

		std::cout << "\n--- form with invalid grade (0 to sign) ---" << std::endl;
		Form f5("sign0form", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- form with invalid grade (151 to execute) ---" << std::endl;
		Form f6("execute151form", 50, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
