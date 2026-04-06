/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:50:27 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 18:10:24 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon(void) {}

const std::string& Weapon::getType(void) const
{
    return this->_type;
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}
