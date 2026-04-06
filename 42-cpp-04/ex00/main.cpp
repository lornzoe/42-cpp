/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:02:06 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:40 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Testing Animal classes with virtual functions ===" << std::endl;
	Animal *animal = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	std::cout << "\nTesting getType():" << std::endl;
	std::cout << "animal->getType(): " << animal->getType() << std::endl;
	std::cout << "dog->getType(): " << dog->getType() << std::endl;
	std::cout << "cat->getType(): " << cat->getType() << std::endl;

	std::cout << "\nTesting makeSound() - virtual functions:" << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n=== Deleting animals ===" << std::endl;
	delete animal;
	delete dog;
	delete cat;

	std::cout << "\n=== Testing WrongAnimal classes (no virtual functions) ===" << std::endl;
	WrongAnimal *wrongAnimal = new WrongAnimal();
	WrongAnimal *wrongCat = new WrongCat();

	std::cout << "\nTesting getType():" << std::endl;
	std::cout << "wrongAnimal->getType(): " << wrongAnimal->getType() << std::endl;
	std::cout << "wrongCat->getType(): " << wrongCat->getType() << std::endl;

	std::cout << "\nTesting makeSound() - no virtual functions:" << std::endl;
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	std::cout << "\n=== Deleting wrong animals ===" << std::endl;
	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
