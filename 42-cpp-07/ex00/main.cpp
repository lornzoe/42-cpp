/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:12:31 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:18:24 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TemplateFunctions.hpp"

int main() {
    std::cout << "add int: " << add<int>(2, 3) << std::endl;
    std::cout << "sub int: " << subtract<int>(5, 2) << std::endl;
    std::cout << "mul double: " << multiply<double>(2.5, 4.0) << std::endl;
    std::cout << "div double: " << divide<double>(10.0, 2.0) << std::endl;
    std::cout << "static add: " << MathOps<int>::add(5, 6) << std::endl;
    std::cout << "static div: " << MathOps<double>::divide(10.0, 4.0) << std::endl;
    try {
        divide<int>(1, 0);
    } catch (const std::exception &e) {
        std::cout << "Expected error: " << e.what() << std::endl;
    }
    return 0;
}
