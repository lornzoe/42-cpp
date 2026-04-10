/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:57:40 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/11 00:03:05 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void) {
	ScavTrap scav("scavvy");
	
	std::cout << std::endl;

	scav.attack("something");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	
	ScavTrap *scav2 = new ScavTrap(scav);
	scav2->guardGate();
	delete scav2;
	
	std::cout << std::endl;

	return 0;
}
