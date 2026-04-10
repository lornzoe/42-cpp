/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:04:37 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/11 07:08:41 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
#include "AMateria.hpp"

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
