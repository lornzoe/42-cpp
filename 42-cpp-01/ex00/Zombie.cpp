/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:14:04 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 06:30:36 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
    return;
}

Zombie::~Zombie(void) {
    std::cout << this->_name << ": Destroyed" << std::endl;
    return;
}

void Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}