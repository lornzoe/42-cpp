/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:26:34 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/16 17:32:12 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int n) : n(n) {}

Span::Span(const Span &other) : n(other.n), data(other.data) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        n = other.n;
        data = other.data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int v) {
    if (data.size() >= n)
        throw std::overflow_error("Span is full");
    data.push_back(v);
}

unsigned int Span::shortestSpan() const {
    if (data.size() < 2)
        throw std::runtime_error("Not enough numbers for span");

    std::vector<int> tmp(data.begin(), data.end());
    std::sort(tmp.begin(), tmp.end());

    unsigned int best = static_cast<unsigned int>(tmp[1] - tmp[0]);
    for (size_t i = 1; i + 1 < tmp.size(); ++i) {
        unsigned int d = static_cast<unsigned int>(tmp[i + 1] - tmp[i]);
        if (d < best)
            best = d;
    }
    return best;
}

unsigned int Span::longestSpan() const {
    if (data.size() < 2)
        throw std::runtime_error("Not enough numbers for span");

    int min = *std::min_element(data.begin(), data.end());
    int max = *std::max_element(data.begin(), data.end());
    return static_cast<unsigned int>(max - min);
}
