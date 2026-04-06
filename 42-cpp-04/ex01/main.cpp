/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:03:10 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:42 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=== Creating 10 animals (5 dogs, 5 cats) ===" << std::endl;
	Animal *animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();

	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	std::cout << "\n=== Testing makeSound() and getType() ===" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << "\n=== Testing deep copy and brain storage ===" << std::endl;
	Dog *dog1 = new Dog();
	dog1->getBrain()->setIdea(0, "Chase the ball");
	dog1->getBrain()->setIdea(1, "Find food");

	Dog *dog2 = new Dog(*dog1);
	std::cout << "dog1 brain idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 brain idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << "dog1 brain idea[1]: " << dog1->getBrain()->getIdea(1) << std::endl;
	std::cout << "dog2 brain idea[1]: " << dog2->getBrain()->getIdea(1) << std::endl;

	std::cout << "\nChanging dog2 brain idea[0]:" << std::endl;
	dog2->getBrain()->setIdea(0, "Sleep on couch");
	std::cout << "dog1 brain idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 brain idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;

	delete dog1;
	delete dog2;

	std::cout << "\n=== Deleting all animals ===" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	return 0;
}
