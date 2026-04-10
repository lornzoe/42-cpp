/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:57:55 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/10 19:56:24 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_name << " destructed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " has no energy left!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " scavs " << target << " all over the place, causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode." << std::endl;
}
