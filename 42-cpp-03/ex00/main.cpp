/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:57:07 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/10 19:39:07 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	{
		ClapTrap clap("attacktrap");
		for (int i = 0; i < 10; i++)
		{
			clap.attack("nothing");
		}
		clap.attack("something");
	}
	std::cout << std::endl;
	{
		ClapTrap clap2("deadtrap");
		for (int i = 0; i < 10; i++)
		{
			clap2.takeDamage(1);
		}
		clap2.takeDamage(1);
		clap2.beRepaired(1);
		clap2.attack("something else");
	}
	std::cout << std::endl;
	{
		ClapTrap clap3("healtrap");
		for (int i = 0; i < 10; i++)
		{
			clap3.beRepaired(1);
		}
		clap3.beRepaired(1);
	}
	return 0;
}
