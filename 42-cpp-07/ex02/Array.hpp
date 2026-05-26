/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:12:50 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/26 15:07:26 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template<typename T>
class Array
{
    private:
        T* _data;
        unsigned int n;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();

        std::size_t size() const;
        T &operator[](std::size_t index);
        const T &operator[](std::size_t index) const;
};

#include "Array.tpp"

#endif // ARRAY_HPP
