/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:58:18 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/11 00:10:42 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->_name << " destructed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (_hitPoints == 0)
		std::cout << "FragTrap " << this->_name << " is out of HP and cannot request high fives (positively)! :(" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " requests high fives (positively)!" << std::endl;
}
