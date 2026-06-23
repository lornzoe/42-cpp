/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:18:18 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/23 21:41:06 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

// static bool isSorted(const std::vector<int> &v) {
// 	for (size_t i = 1; i < v.size(); ++i) {
// 		if (v[i-1] > v[i]) return false;
// 	}
// 	return true;
// }

std::vector<int> PmergeMe::sortVectorStdSort(std::vector<int> input) {
	std::vector<int> out(input);
	std::sort(out.begin(), out.end());
	return out;
}

std::deque<int> PmergeMe::sortDequeStdSort(std::deque<int> input) {
	std::deque<int> out(input);
	std::sort(out.begin(), out.end());
	return out;
}

struct pair {
	int winner;
	int loser;
};

std::vector<int> PmergeMe::FordJohnson(std::vector<int> input)
{
	size_t size = input.size();
	if (size <= 1)
		return input;

	int extra;
	int groups = input.size() / 2;
	std::vector<int> A, B, winners;

	std::vector<pair> pairs;
	for (int i = 0; i < groups; ++i) {
		pair p;
		p.winner = input[2*i];
		p.loser = input[2*i + 1];
		if (p.winner < p.loser)
			std::swap(p.winner, p.loser);
		pairs.push_back(p);
	}
	if (size % 2)
		extra = *(input.end() - 1);
	
	#ifdef DEBUG
	std::cout << "pairs: "<< std::endl;
	for (std::vector<pair>::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		std:: cout << "[" << it->winner << "," << it->loser << "] ";
	}
	if (input.size() % 2)
	{
		std::cout << extra << ' ';
	}
	std::cout << std::endl << "===" << std::endl;
	#endif
	
	// split to A and B

	for (std::vector<pair>::iterator it = pairs.begin(); it != pairs.end(); ++it)
		winners.push_back(it->winner);
	std::vector<int> sorted_winners = FordJohnson(winners);
	for (size_t i = 0; i < sorted_winners.size(); ++i)
	{
		int winner = sorted_winners[i];
		A.push_back(winner);
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].winner == winner)
			{
				B.push_back(pairs[j].loser);
				break;
			}
		}
	}
	if (size % 2)
		B.push_back(extra);
	std::cout << "A: ";
	for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "B: ";
	for (std::vector<int>::iterator it = B.begin(); it != B.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	// now figure out where to put B while going through
	// first element of B to A is free; can go to the first
	// 
	return std::vector<int>();
}
