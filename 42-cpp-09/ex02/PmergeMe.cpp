/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:18:18 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:55 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

// Using straightforward sort (not full Ford-Johnson) but using two containers
std::vector<int> PmergeMe::sortVector(const std::vector<int> &input) {
	std::vector<int> out(input);
	std::sort(out.begin(), out.end());
	return out;
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> &input) {
	std::deque<int> out(input);
	std::sort(out.begin(), out.end());
	return out;
}
