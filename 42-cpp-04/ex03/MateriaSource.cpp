/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:04:52 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:04:59 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.templates[i] != NULL)
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (templates[i] != NULL)
				delete templates[i];
			if (other.templates[i] != NULL)
				templates[i] = other.templates[i]->clone();
			else
				templates[i] = NULL;
		}
	}
	std::cout << "MateriaSource assignment operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] != NULL)
			delete templates[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] == NULL)
		{
			templates[i] = m;
			std::cout << "Learned materia: " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "Cannot learn more materias! Storage full." << std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] != NULL && templates[i]->getType() == type)
		{
			std::cout << "Created materia: " << type << std::endl;
			return templates[i]->clone();
		}
	}
	std::cout << "Cannot create materia of type: " << type << std::endl;
	return NULL;
}
