/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:11:30 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:52 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <typeinfo>

Base	*generate(void)
{
	int random = rand() % 3;

	if (random == 0)
	{
		std::cout << "Generated type: A" << std::endl;
		return (new A());
	}
	else if (random == 1)
	{
		std::cout << "Generated type: B" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "Generated type: C" << std::endl;
		return (new C());
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Identify via pointer: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Identify via pointer: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Identify via pointer: C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Identify via reference: A" << std::endl;
		return;
	}
	catch (std::bad_cast &e)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Identify via reference: B" << std::endl;
		return;
	}
	catch (std::bad_cast &e)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Identify via reference: C" << std::endl;
		return;
	}
	catch (std::bad_cast &e)
	{
	}
}

int main(void)
{
	std::cout << "=== Testing Type Identification ===" << std::endl;

	srand(time(0));

	std::cout << "\n--- Test 1: Generate and Identify via Pointer ---" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base *obj = generate();
		identify(obj);
		delete obj;
	}

	std::cout << "\n--- Test 2: Generate and Identify via Reference ---" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base *obj = generate();
		identify(*obj);
		delete obj;
	}

	return (0);
}
