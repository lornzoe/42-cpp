/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:03:43 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:04:59 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Animal *animal = new Animal(); // This will cause compilation error - Animal is abstract!

	std::cout << "=== Creating dogs and cats (Animal is abstract) ===" << std::endl;
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	std::cout << "\nTesting getType():" << std::endl;
	std::cout << "dog->getType(): " << dog->getType() << std::endl;
	std::cout << "cat->getType(): " << cat->getType() << std::endl;

	std::cout << "\nTesting makeSound() - pure virtual function:" << std::endl;
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n=== Cleaning up ===" << std::endl;
	delete dog;
	delete cat;

	return 0;
}
