/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:57:07 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:36 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clap("CL4P-TP");
	
	clap.attack("enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);
	
	// Test with no energy
	for (int i = 0; i < 10; i++) {
		clap.attack("enemy");
	}
	clap.attack("enemy"); // Should fail - no energy
	
	return 0;
}
