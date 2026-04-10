/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:57:40 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/10 23:49:39 by lyanga           ###   ########.fr       */
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
	scav.guardGate();
	
	std::cout << std::endl;

	return 0;
}
