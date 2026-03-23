/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:12:50 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:18:24 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template<typename T>
class Array
{
private:
    T* _data;
    std::size_t _size;

public:
    Array(): _data(NULL), _size(0) {}
    explicit Array(std::size_t n): _data(NULL), _size(n) {
        if (_size > 0)
            _data = new T[_size];
    }

    Array(const Array &other): _data(NULL), _size(other._size) {
        if (_size > 0) {
            _data = new T[_size];
            for (std::size_t i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            delete [] _data;
            _size = other._size;
            _data = NULL;
            if (_size > 0) {
                _data = new T[_size];
                for (std::size_t i = 0; i < _size; ++i)
                    _data[i] = other._data[i];
            }
        }
        return *this;
    }

    ~Array() { delete [] _data; }

    std::size_t size() const { return _size; }

    T &operator[](std::size_t index) {
        if (index >= _size)
            throw std::out_of_range("Array index out of range");
        return _data[index];
    }

    const T &operator[](std::size_t index) const {
        if (index >= _size)
            throw std::out_of_range("Array index out of range");
        return _data[index];
    }
};

#endif // ARRAY_HPP
