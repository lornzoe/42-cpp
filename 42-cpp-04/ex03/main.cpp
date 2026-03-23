/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:04:42 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:04:59 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "=== Creating MateriaSource and learning Materias ===" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n=== Creating Characters ===" << std::endl;
	ICharacter *me = new Character("me");
	ICharacter *bob = new Character("bob");

	std::cout << "\n=== Equipping Materias ===" << std::endl;
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\n=== Using Materias ===" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << "\n=== Testing unequip ===" << std::endl;
	me->unequip(0);
	me->use(0, *bob);

	std::cout << "\n=== Trying to equip on full inventory ===" << std::endl;
	tmp = src->createMateria("cure");
	if (!me->equip(tmp))
		delete tmp;

	std::cout << "\n=== Cleanup ===" << std::endl;
	delete me;
	delete bob;
	delete src;

	return 0;
}
