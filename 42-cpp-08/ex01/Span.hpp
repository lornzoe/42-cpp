/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:17:23 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:53 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
public:
	explicit Span(unsigned int n): _n(n) {}
	Span(const Span &other): _n(other._n), _data(other._data) {}
	Span &operator=(const Span &other) { if (this != &other) { _n = other._n; _data = other._data; } return *this; }
	~Span() {}

	void addNumber(int v) {
		if (_data.size() >= _n)
			throw std::overflow_error("Span is full");
		_data.push_back(v);
	}

	unsigned int shortestSpan() const {
		if (_data.size() < 2)
			throw std::runtime_error("Not enough numbers for span");
		std::vector<int> tmp(_data.begin(), _data.end());
		std::sort(tmp.begin(), tmp.end());
		unsigned int best = (unsigned int)(tmp[1] - tmp[0]);
		for (size_t i = 1; i + 1 < tmp.size(); ++i) {
			unsigned int d = (unsigned int)(tmp[i+1] - tmp[i]);
			if (d < best) best = d;
		}
		return best;
	}

	unsigned int longestSpan() const {
		if (_data.size() < 2)
			throw std::runtime_error("Not enough numbers for span");
		int min = *std::min_element(_data.begin(), _data.end());
		int max = *std::max_element(_data.begin(), _data.end());
		return (unsigned int)(max - min);
	}

private:
	unsigned int _n;
	std::vector<int> _data;
};

#endif // SPAN_HPP
