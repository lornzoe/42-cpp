/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:18:12 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:18:24 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include "PmergeMe.hpp"

static bool isNumber(const std::string &s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (i == 0 && (s[i] == '+' || s[i] == '-')) continue;
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: provide at least one integer" << std::endl;
        return 1;
    }
    std::vector<int> vi;
    std::deque<int> di;

    for (int i = 1; i < argc; ++i) {
        std::string s(argv[i]);
        if (!isNumber(s)) {
            std::cerr << "Error: invalid number '" << s << "'" << std::endl;
            return 1;
        }
        int v = std::atoi(s.c_str());
        vi.push_back(v);
        di.push_back(v);
    }

    std::cout << "Before:";
    for (size_t i = 0; i < vi.size(); ++i) std::cout << " " << vi[i];
    std::cout << std::endl;

    clock_t start_v = clock();
    std::vector<int> sorted_v = PmergeMe::sortVector(vi);
    clock_t end_v = clock();

    clock_t start_d = clock();
    std::deque<int> sorted_d = PmergeMe::sortDeque(di);
    clock_t end_d = clock();

    std::cout << "After:";
    for (size_t i = 0; i < sorted_v.size(); ++i) std::cout << " " << sorted_v[i];
    std::cout << std::endl;

    double time_v = double(end_v - start_v) / CLOCKS_PER_SEC * 1000000.0;
    double time_d = double(end_d - start_d) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << vi.size() << " elements with std::vector : " << time_v << " us" << std::endl;
    std::cout << "Time to process a range of " << di.size() << " elements with std::deque : " << time_d << " us" << std::endl;

    return 0;
}
