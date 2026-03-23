/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:12:53 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:18:24 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> a(5);
    for (std::size_t i = 0; i < a.size(); ++i)
        a[i] = i * 10;

    for (std::size_t i = 0; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    Array<int> b = a;
    b[0] = 42;
    std::cout << "a[0]=" << a[0] << " b[0]=" << b[0] << std::endl;

    try {
        a[10] = 1;
    } catch (const std::exception &e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    return 0;
}
