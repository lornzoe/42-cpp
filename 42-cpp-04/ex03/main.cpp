/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:04:42 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/11 07:16:13 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	// Test code from subject.pdf
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n === end of subject.pdf test cases ===" << std::endl;
	std::cout << " === start of own test cases ===\n" << std::endl;
	
	// More test code
	{
		AMateria *m;

		// MateriaSource
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		// attempt to learn more than capacity
		m = new Ice();
		src->learnMateria(m); // should report storage full
		delete m;
		m = NULL;

		// create unknown materia
		AMateria *unknown = src->createMateria("fire");
		if (unknown == NULL)
			std::cout << "createMateria correctly returned NULL for unknown type" << std::endl;

		// Characters and inventory edge cases
		Character alice("Alice");
		Character copyAlice;

		// equip NULL
		if (!alice.equip(NULL))
			std::cout << "equip(NULL) correctly returned false" << std::endl;

		// equip up to capacity
		m = src->createMateria("ice"); alice.equip(m);
		m = src->createMateria("cure"); alice.equip(m);
		m = src->createMateria("ice"); alice.equip(m);
		m = src->createMateria("cure"); alice.equip(m);

		// try to equip when full (create returns a new clone each time)
		m = src->createMateria("ice");
		if (!alice.equip(m))
		{
			std::cout << "Alice inventory full; deleting extra materia" << std::endl;
			delete m; // caller must delete when equip fails
		}

		// use valid and invalid indexes
		Character target("Target");
		alice.use(0, target);
		alice.use(3, target);
		alice.use(4, target); // invalid index

		// unequip a slot and ensure it no longer use
		m = alice.getInventory(1);
		if (alice.unequip(1))
		{
			std::cout << "Unequipped slot 1 from Alice" << std::endl;
			delete m;
		}
		m = NULL;
		alice.use(1, target); // should say nothing at slot

		// unequip invalid
		if (!alice.unequip(10))
			std::cout << "unequip returned false for invalid index" << std::endl;

		// test copy constructor (deep copy) and assignment
		copyAlice = alice; // assignment
		Character bob("Bob");
		Character bobCopy(bob); // copy constructor with empty inventory

		// After assignment, using copyAlice should work and not affect original when unequipped
		copyAlice.use(0, target);
		m = copyAlice.getInventory(0);
		copyAlice.unequip(0);
		delete m;
		m = NULL;
		// original alice should still have its materia at slot 0
		alice.use(0, target);

		delete src;
	}

	return 0;
}
