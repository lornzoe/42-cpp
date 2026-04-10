/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:04:18 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/11 07:09:32 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : type("unknown")
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria constructor (type) called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "AMateria assignment operator called" << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
