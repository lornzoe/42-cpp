/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:11:30 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/08 11:43:46 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <exception>
#include <iostream>
#include <cstdlib>

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
	catch (std::exception &e)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Identify via reference: B" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Identify via reference: C" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}
}

int main(void)
{
	srand(time(0));

	std::cout <<"--- generate and identify via ptr ---" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base *obj = generate();
		identify(obj);
		delete obj;
	}

	std::cout << std::endl << "--- generate and identify via ref ---" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base *obj = generate();
		identify(*obj);
		delete obj;
	}

	return (0);
}
