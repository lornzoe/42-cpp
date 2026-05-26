/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:43:26 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/26 17:19:30 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <stdexcept>

template<typename T>
Array<T>::Array() : _data(NULL), n(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _data(NULL), n(n) {
    if (n > 0)
        _data = new T[n](); 
}

template<typename T>
Array<T>::Array(const Array &other) : _data(NULL), n(other.n) {
    if (n > 0) {
        _data = new T[n]();
        for (unsigned int i = 0; i < n; ++i)
            _data[i] = other._data[i];
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        Array<T> temp(other);
        // Swap this and temp
        unsigned int temp_n = this->n;
        this->n = temp.n;
        temp.n = temp_n;
        
        T* temp_data = this->_data;
        this->_data = temp._data;
        temp._data = temp_data;
    }
    // temp will be deleted
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete [] _data;
}

template<typename T>
std::size_t Array<T>::size() const {
    return n;
}

template<typename T>
T &Array<T>::operator[](std::size_t index) {
    if (index >= n)
        throw std::out_of_range("Array index out of range");
    return _data[index];
}

template<typename T>
const T &Array<T>::operator[](std::size_t index) const {
    if (index >= n)
        throw std::out_of_range("Array index out of range");
    return _data[index];
}

#endif // ARRAY_TPP
