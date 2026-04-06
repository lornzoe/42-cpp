/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:00:20 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:39 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap diamond("Diamond");
	
	diamond.whoAmI();
	diamond.attack("enemy");
	diamond.takeDamage(30);
	diamond.beRepaired(20);
	diamond.guardGate();
	diamond.highFivesGuys();
	
	return 0;
}
