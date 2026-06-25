/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:18:18 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/25 09:50:37 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>

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

template <typename F>
static int binarySearchInsertion(const F& container, int target, int high = -1)
{
	int low = 0;
	if (high < 0)
		high = container.size();

	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (container[mid] < target)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

template <typename F>
static void logContatiners(const F& A, const F& B, std::string initMessage = "")
{
	std::cout << initMessage << " A[ ";
	for (size_t j = 0; j < A.size(); ++j)
		std::cout << A[j] << " ";
	std::cout << "] B[ ";
	for (size_t j = 0; j < B.size(); ++j)
		std::cout << B[j] << " ";
	std::cout << "]" << std::endl;

}

static std::vector<size_t> getJacobstalSequence(size_t n)
{
	std::vector<size_t> jacob;
	//jacob.push_back(1);
	if (n == 0)
		return jacob;
	
	jacob.push_back(1);
	if (n == 1)
		return jacob;
	
	jacob.push_back(3);
	while (true) {
		size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
		if (next >= n) {
			jacob.push_back(n); // Cap it at the max index size needed
			break;
		}
		jacob.push_back(next);
	}
	return jacob;
}

std::vector<int> PmergeMe::fordJohnson(std::vector<int> input)
{
	std::cout << "=== entering fj recusion, down by 1" << std::endl;
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

	for (std::vector<pair>::iterator it = pairs.begin(); it != pairs.end(); ++it)
		winners.push_back(it->winner);
		
	A = fordJohnson(winners);

	std::cout << "winners: [ ";
	for (size_t i = 0; i < A.size(); ++i)
	{
		std::cout << A[i] << ' ';

		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].winner == A[i])
			{
				B.push_back(pairs[j].loser);
				break;
			}
		}
	}
	// logging
	std::cout << "]" << std::endl;
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
	if (!B.empty()) {
		A.insert(A.begin(), B[0]);
		logContatiners(A, B, "free insert; ");
	}


	// AI GENERATED SOLUTION
	// TAKE SOME TIME TO FIGURE OUT WHAT IS GOING ON HERE
	{
		std::vector<size_t> jacobSeq = getJacobstalSequence(B.size());
		size_t last_inserted_idx = 1; 

		for (size_t k = 1; k < jacobSeq.size(); ++k) 
		{
			size_t upper_bound_idx = jacobSeq[k];
			if (upper_bound_idx > B.size()) {
				upper_bound_idx = B.size();
			}
			
			for (size_t i = (upper_bound_idx) - 1; i >= (last_inserted_idx); --i) {
				int target = B[i];
				
				// 1. Find the actual winner matching this specific loser target
				int matching_winner = -1;
				for (size_t j = 0; j < pairs.size(); ++j) {
					if (pairs[j].loser == target) {
						matching_winner = pairs[j].winner;
						break;
					}
				}

				// 2. Locate where that winner is currently sitting in A to define the binary search upper bound
				std::vector<int>::iterator winner_it = std::find(A.begin(), A.end(), matching_winner);
				int high_bound = std::distance(A.begin(), winner_it);

				// 3. Perform binary search and insert safely
				int pos = binarySearchInsertion(A, target, high_bound);
				A.insert(A.begin() + pos, target);
				
				std::stringstream ss;
				ss << "ins " << target << " to pos " << pos << ";";
				logContatiners(A, B, ss.str());
			}
			last_inserted_idx = upper_bound_idx;
		}
	}

	// if (size % 2 != 0) {
	//     int pos = binarySearchInsertion(A, extra, A.size());
	//     A.insert(A.begin() + pos, extra);
	// 	std::stringstream ss;
	// 	ss << "ins " << extra << "(straggler)" << " to pos " << pos << ";";
	// 	logContatiners(A, B, ss.str());
	// }
	
	// old insertion
	/*
	for (size_t i  = 1; i < B.size(); ++i)
	{
		int pos = binarySearchInsertion(A, B[i], i * 2);
		A.insert(A.begin() + pos, B[i]);
	
		std::stringstream ss;
		ss << "ins " << B[i] << "from i of " << i << " to pos " << pos << ";";
		logContatiners(A, B, ss.str());
	}
	*/

	std::cout << "=== end of recursion, going up one" << std::endl;
	return A;
}
