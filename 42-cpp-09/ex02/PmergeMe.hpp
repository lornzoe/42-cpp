/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:18:20 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/23 17:31:37 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

namespace PmergeMe 
{
	std::vector<int> sortVectorStdSort(std::vector<int> input);
	std::deque<int> sortDequeStdSort(std::deque<int> input);

	std::vector<int> FordJohnson(std::vector<int> input);
	std::deque<int> sortDequeMergeInsert(std::deque<int> input);
};

#endif // PMERGEME_HPP
