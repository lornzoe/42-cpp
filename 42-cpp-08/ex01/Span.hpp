/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:23 by lyanga            #+#    #+#             */
/*   Updated: 2026/06/23 21:42:07 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span {
public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int v);

    template <typename T>
    void addNumber(T start, T end);
    
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

private:
    unsigned int n;
    std::vector<int> data;
};

template <typename T>
void Span::addNumber(T start, T end)
{
    while (start != end)
    {
        if (data.size() >= n)
            throw std::overflow_error("Span is full");
        addNumber(*start);
        std::cout << "added: " << *start << std::endl;
        ++start;
    }
}

#endif