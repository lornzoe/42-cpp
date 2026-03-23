/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:18:20 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:18:24 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    static std::vector<int> sortVector(const std::vector<int> &input);
    static std::deque<int> sortDeque(const std::deque<int> &input);
};

#endif // PMERGEME_HPP
