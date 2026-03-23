/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:26 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:18:24 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> m;
    m.push(5);
    m.push(17);
    std::cout << "top: " << m.top() << std::endl;
    m.pop();
    std::cout << "size: " << m.size() << std::endl;
    m.push(3);
    m.push(5);
    m.push(737);
    
    for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}
