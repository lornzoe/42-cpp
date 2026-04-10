/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:00:20 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/11 00:24:40 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap diamond("Diamond");
	
	diamond.whoAmI();
	diamond.attack("enemy");
	diamond.takeDamage(30);
	diamond.beRepaired(20);
	
	std::cout << std::endl;

	for (int i = 0; i < 50; i++) {
		// For checking energy amount (50, Scavtrap)
		diamond.attack("air");		
	}

	std::cout << std::endl;

	diamond.guardGate();
	diamond.highFivesGuys();
	
	return 0;
}
