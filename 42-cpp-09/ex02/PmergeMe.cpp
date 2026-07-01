/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:18:18 by lyanga            #+#    #+#             */
/*   Updated: 2026/07/02 03:54:03 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>

static bool isSorted(const std::vector<int> &v) {
	for (std::size_t i = 1; i < v.size(); ++i) {
		if (v[i-1] > v[i]) return false;
	}
	return true;
}

int PmergeMe::comparison = 0;

long long get_sorting_number(long long n) {
    if (n <= 0) {
        return 0;
    }

    long long target = 3 * n + 3;
    long long z = 0;
    
	while (target >>= 1) {
        z++;
    }

    long long power_of_two = 1LL << (z + 2);
    long long result = n * (z - 1) - ((power_of_two - 3 * z) / 6);

    return result;
}

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
		PmergeMe::comparison += 1;
	}
	return low;
}

template <typename F>
static void logContatiners(const F& A, const F& B, std::string initMessage = "")
{
	std::cout << initMessage << " A[ ";
	for (std::size_t j = 0; j < A.size(); ++j)
		std::cout << A[j] << " ";
	std::cout << "] B[ ";
	for (std::size_t j = 0; j < B.size(); ++j)
		std::cout << B[j] << " ";
	std::cout << "]" << std::endl;

}

static std::vector<std::size_t> getJacobsthalSequence(std::size_t n)
{
	std::vector<std::size_t> jacob;
	//jacob.push_back(1);
	if (n == 0)
		return jacob;
	
	jacob.push_back(1);
	if (n == 1)
		return jacob;
	
	jacob.push_back(3);
	while (true) {
		std::size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
		if (next >= n) {
			jacob.push_back(n); // Cap it at the max index size instead
			break;
		}
		jacob.push_back(next);
	}
	return jacob;
}

std::vector<int> PmergeMe::fordJohnson(std::vector<int> input, bool isTop)
{
	std::cout << "=== entering fj recusion, down by 1" << std::endl;
	std::size_t size = input.size();
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
		PmergeMe::comparison += 1;
		pairs.push_back(p);
	}
	if (size % 2)
		extra = *(input.end() - 1);

	for (std::vector<pair>::iterator it = pairs.begin(); it != pairs.end(); ++it)
		winners.push_back(it->winner);
		
	A = fordJohnson(winners);

	std::cout << "winners: [ ";
	for (std::size_t i = 0; i < A.size(); ++i)
	{
		std::cout << A[i] << ' ';

		for (std::size_t j = 0; j < pairs.size(); ++j)
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

	std::vector<std::size_t> jacobSeq = getJacobsthalSequence(B.size());
	std::size_t last_inserted_idx = 1; 

	for (std::size_t k = 1; k < jacobSeq.size(); ++k) 
	{
		std::size_t upper_bound_idx = jacobSeq[k];
		if (upper_bound_idx > B.size()) {
			upper_bound_idx = B.size();
		}
		std::cout << "jacobsthal # = " << jacobSeq[k]
			<< ", upperBound is at " << upper_bound_idx << "(index "<< upper_bound_idx - 1 << ")" <<std::endl;
		for (std::size_t i = (upper_bound_idx) - 1; i >= (last_inserted_idx); --i)
		{
			int target = B[i];
			int matching_winner = -1;
			for (std::size_t j = 0; j < pairs.size(); ++j) {
				if (pairs[j].loser == target) {
					matching_winner = pairs[j].winner;
					break;
				}
			}
			std::vector<int>::iterator winner_it = std::find(A.begin(), A.end(), matching_winner);
			int high_bound = std::distance(A.begin(), winner_it);
			int pos = binarySearchInsertion(A, target, high_bound);
			A.insert(A.begin() + pos, target);
			
			std::stringstream ss;
			ss << "index " << i << " (B[i] = " << target << ") to pos " << pos << ";";
			logContatiners(A, B, ss.str());
			std::cout << "comparisons so far: " << comparison << std::endl;
		}
		last_inserted_idx = upper_bound_idx;
	}

	std::cout << "=== end of recursion, going up one" << std::endl;
	std::cout << "SORTED CHECK: ";
	if (isSorted(A))
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	
	if (isTop)
		std::cout << "EXPECTED MAX COMPARISONS: " << get_sorting_number(A.size()) << std::endl;
	return A;
}
