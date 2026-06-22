/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:12:42 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/26 14:44:08 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename T, typename F>
void iter(T *array, size_t length, F func)
{
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}

#endif // ITER_HPP
