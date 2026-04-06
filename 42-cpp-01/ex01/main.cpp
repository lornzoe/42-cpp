/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:32:27 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 16:49:46 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Horde Zombie");

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;

    return 0;
}
