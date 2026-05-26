/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:12:39 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/26 12:59:48 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T> void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T> const T&	min(T& a, T& b)
{
	return (a < b) ? a : b; 
}

template<typename T> const T&	max(T& a, T& b)
{
	return (a > b) ? a : b;
}

#endif