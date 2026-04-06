/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:12:45 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:52 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void printInt(int &x) { x += 1; std::cout << x << " "; }
void printStr(std::string &s) { s += "!"; std::cout << s << " "; }

int main() {
	int arr[] = {1, 2, 3, 4};
	iter<int>(arr, 4, printInt);
	std::cout << std::endl;

	std::string sarr[] = {"a", "b", "c"};
	iter<std::string>(sarr, 3, printStr);
	std::cout << std::endl;

	return 0;
}
