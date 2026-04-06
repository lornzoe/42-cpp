/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:11:42 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 17:04:10 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    randomChump("Stack Zombie");
    
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    delete heapZombie;
    
    return 0;
}
