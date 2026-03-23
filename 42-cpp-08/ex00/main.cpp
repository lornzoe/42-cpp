/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:09 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:18:24 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    for (int i = 1; i <= 5; ++i) v.push_back(i);
    if (easyfind(v, 3) != v.end()) std::cout << "found 3 in vector\n";
    if (easyfind(v, 99) == v.end()) std::cout << "99 not found in vector\n";

    std::list<int> l;
    l.push_back(11);
    l.push_back(22);
    if (easyfind(l, 22) != l.end()) std::cout << "found 22 in list\n";

    return 0;
}
