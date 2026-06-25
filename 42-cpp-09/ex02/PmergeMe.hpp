/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:18:20 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/25 16:30:29 by lyanga           ###   ########.fr       */
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

	extern int comparison;
	std::vector<int> fordJohnson(std::vector<int> input, bool isTop = false);
	std::deque<int> fordJohnson(std::deque<int> input, bool istop = false);
};

#endif // PMERGEME_HPP
