/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:50:11 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 06:51:23 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
    return;
}

HumanB::~HumanB(void) {
    return;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}

void HumanB::attack(void) {
    if (this->_weapon) {
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    } else {
        std::cout << this->_name << " has no weapon" << std::endl;
    }
}