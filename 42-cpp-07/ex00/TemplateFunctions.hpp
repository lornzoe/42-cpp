/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemplateFunctions.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:12:39 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:52 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATEFUNCTIONS_HPP
#define TEMPLATEFUNCTIONS_HPP

#include <stdexcept>

template<typename T>
class MathOps
{
public:
	static T add(T a, T b) { return a + b; }
	static T subtract(T a, T b) { return a - b; }
	static T multiply(T a, T b) { return a * b; }
	static T divide(T a, T b) {
		if (b == 0) throw std::runtime_error("division by zero");
		return a / b;
	}
};

template<typename T>
T add(T a, T b) { return a + b; }

template<typename T>
T subtract(T a, T b) { return a - b; }

template<typename T>
T multiply(T a, T b) { return a * b; }

template<typename T>
T divide(T a, T b) {
	if (b == 0) throw std::runtime_error("division by zero");
	return a / b;
}

#endif // TEMPLATEFUNCTIONS_HPP
