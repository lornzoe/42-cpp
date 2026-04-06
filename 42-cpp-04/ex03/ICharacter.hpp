/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:04:37 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:44 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include <string>

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {};

	virtual std::string const &getName() const = 0;
	virtual bool equip(AMateria *m) = 0;
	virtual bool unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};

#endif
