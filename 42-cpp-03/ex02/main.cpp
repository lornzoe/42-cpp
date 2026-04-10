/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:58:23 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/11 00:11:47 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void) {
	FragTrap frag("fraggy");

	std::cout << std::endl;

	frag.attack("enemy");
	frag.takeDamage(20);
	frag.beRepaired(10);
	frag.highFivesGuys();
	frag.takeDamage(90);
	frag.highFivesGuys();

	std::cout << std::endl;
	
	return 0;
}
