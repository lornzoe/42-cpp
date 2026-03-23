/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:10:37 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:11:42 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>
#include <sstream>
#include <cstdlib>
#include <cfloat>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter(void);
	ScalarConverter	&operator=(const ScalarConverter &rhs);

public:
	static void	convert(const std::string &str);

	class ImpossibleConversionException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};

	class NonDisplayableException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
};

#endif
