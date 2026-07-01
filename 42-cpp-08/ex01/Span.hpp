/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:23 by lyanga            #+#    #+#             */
/*   Updated: 2026/07/02 01:04:01 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <iterator>
#include <stdexcept>

class Span {
public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int v);

    template <typename T>
    void addNumber(T start, T end);
    
    long shortestSpan() const;
    long longestSpan() const;

private:
    unsigned int n;
    std::vector<int> data;
};

template <typename T>
void Span::addNumber(T start, T end)
{
    typename std::iterator_traits<T>::difference_type dist = std::distance(start, end);
    if (dist < 0)
        throw std::invalid_argument("Invalid iterator range");

    std::size_t rangeSize = static_cast<std::size_t>(dist);
    if (data.size() + rangeSize > static_cast<std::size_t>(n))
        throw std::length_error("Inserted range will exceed span size");
    data.insert(data.end(), start, end);
}

#endif