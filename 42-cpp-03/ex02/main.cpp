/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:58:23 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/10 21:14:50 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void) {
	FragTrap frag("fraggy");
	
	frag.attack("enemy");
	frag.takeDamage(20);
	frag.beRepaired(10);
	frag.highFivesGuys();
	
	return 0;
}
