/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:11:42 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 06:27:23 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Stack Zombie");

    return 0;
}