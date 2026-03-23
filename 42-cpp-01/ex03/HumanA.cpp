/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:50:06 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 06:51:23 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
    return;
}

HumanA::~HumanA(void) {
    return;
}

void HumanA::attack(void) {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}