/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:58:23 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 06:58:23 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void) {
    FragTrap frag("FragTrap-001");
    
    frag.attack("enemy");
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFivesGuys();
    
    return 0;
}
