/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:26:34 by lyanga            #+#    #+#             */
/*   Updated: 2026/07/02 01:35:52 by lyanga           ###   ########.fr       */
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
        throw std::length_error("Span is full");
    data.push_back(v);
}

long Span::shortestSpan() const {
    if (data.size() < 2)
        throw std::logic_error("Not enough numbers for span");

    std::vector<int> tmp(data.begin(), data.end());
    std::sort(tmp.begin(), tmp.end());

    long best = static_cast<long>(tmp[1]) - static_cast<long>(tmp[0]);
    for (size_t i = 1; i < tmp.size() - 1; ++i) {
        long d = static_cast<long>(tmp[i + 1]) - static_cast<long>(tmp[i]);
        if (d < best)
            best = d;
    }
    return best;
}

long Span::longestSpan() const {
    if (data.size() < 2)
        throw std::logic_error("Not enough numbers for span");

    long min = *std::min_element(data.begin(), data.end());
    long max = *std::max_element(data.begin(), data.end());
    return (max - min);
}
