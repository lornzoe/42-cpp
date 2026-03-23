/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:04:23 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:04:59 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Unknown")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string &n) : name(n)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other) : name(other.name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] != NULL)
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i] != NULL)
				delete inventory[i];
			if (other.inventory[i] != NULL)
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	std::cout << "Character assignment operator called" << std::endl;
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

std::string const &Character::getName() const
{
	return name;
}

bool Character::equip(AMateria *m)
{
	if (m == NULL)
		return false;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << name << " equipped " << m->getType() << " at slot " << i << std::endl;
			return true;
		}
	}
	std::cout << "Inventory full! Cannot equip " << m->getType() << std::endl;
	return false;
}

bool Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
		return false;
	std::cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
	inventory[idx] = NULL;
	return true;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
	{
		std::cout << name << " has nothing at slot " << idx << std::endl;
		return;
	}
	inventory[idx]->use(target);
}
