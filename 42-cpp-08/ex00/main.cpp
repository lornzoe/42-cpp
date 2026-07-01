/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:09 by lyanga            #+#    #+#             */
/*   Updated: 2026/07/02 03:46:40 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {

	std::cout << "1=============================" << std::endl;

	std::vector<int> v;
	for (std::size_t i = 1; i <= 5; ++i) v.push_back(i);

	if (easyfind(v, 3).first) 
		std::cout << "found 3 in vector: " << *(easyfind(v, 3).second) << std::endl;
	if (!easyfind(v, 99).first)
		std::cout << "99 not found in vector" << std::endl;

	std::cout << "2=============================" << std::endl;

	std::list<int> l;
	l.push_back(11);
	l.push_back(22);
	if (easyfind(l, 22).first)
		std::cout << "found 22 in list: " << *(easyfind(l, 22).second) << std::endl;

	std::cout << "3=============================" << std::endl;

	std::vector<int> empty_vector;
	std::pair<bool, std::vector<int>::iterator> empty_res = easyfind(empty_vector, 42);
	if (!empty_res.first && empty_res.second == empty_vector.end())
		std::cout << "empty container correct response" << std::endl;
	else
		std::cout << "empty container broken" << std::endl;

	std::cout << "4=============================" << std::endl;

	std::pair<bool, std::vector<int>::iterator> res_first = easyfind(v, 1);
	std::pair<bool, std::vector<int>::iterator> res_last = easyfind(v, 5);

	if (res_first.first && *(res_first.second) == 1)
		std::cout << "found correct first element (1)." << std::endl;
	if (res_last.first && *(res_last.second) == 5)
		std::cout << "found correct last element (5)." << std::endl;

	std::cout << "5=============================" << std::endl;
	std::vector<int> duplicates;
	duplicates.push_back(2);
	duplicates.push_back(1);
	duplicates.push_back(7);
	duplicates.push_back(1);

	std::pair<bool, std::vector<int>::iterator> dup_res = easyfind(duplicates, 1);
	if (dup_res.first) {
		if (*(dup_res.second) == 1 
			&& dup_res.second == duplicates.begin() + 1) {
			std::cout << "found correct duplicate (first occurence)" << std::endl;
			*(dup_res.second) = 42;
			if (duplicates[1] == 42 && duplicates[3] == 1)
				std::cout << "verified correct duplicate was pulled" << std::endl;
		}
		else {
			std::cout << "incorrect second value" << std::endl;
		}
	}
	
	std::cout << "6=============================" << std::endl;
	
	std::deque<int> d;
	for (std::size_t i = 1; i <= 5; ++i) 
		d.push_back(i);
	if (easyfind(d, 1).first) 
		std::cout << "found 1 in deque: " << *(easyfind(d, 1).second) << std::endl;
	if (easyfind(d, 5).first) 
		std::cout << "found 5 in deque: " << *(easyfind(d, 5).second) << std::endl;
	if (!easyfind(d, 99).first)
		std::cout << "99 not found in deque" << std::endl;

	
	return 0;
}
