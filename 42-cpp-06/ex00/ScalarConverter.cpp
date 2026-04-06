/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:10:34 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:50 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

static bool	isSpecialFloat(const std::string &str)
{
	return (str == "nanf" || str == "+inff" || str == "-inff" ||
			str == "nan" || str == "+inf" || str == "-inf");
}

static int	checkType(const std::string &str, double &doubleValue)
{
	if (str.empty())
		throw ScalarConverter::ImpossibleConversionException();

	if (isSpecialFloat(str))
	{
		if (str == "nanf" || str == "nan")
			doubleValue = strtod("nan", NULL);
		else if (str == "+inff" || str == "+inf")
			doubleValue = strtod("+inf", NULL);
		else if (str == "-inff" || str == "-inf")
			doubleValue = strtod("-inf", NULL);
		return (3);
	}

	std::string	temp = str;
	size_t		i = 0;

	if (temp[i] == '+' || temp[i] == '-')
		i++;

	if (temp.length() - i == 1 && !std::isdigit(temp[i]))
		return (0);

	int	dotCount = 0;
	int	fCount = 0;

	for (; i < temp.length(); i++)
	{
		if (temp[i] == '.')
		{
			dotCount++;
			if (dotCount > 1 || fCount > 0)
				throw ScalarConverter::ImpossibleConversionException();
		}
		else if (temp[i] == 'f' || temp[i] == 'F')
		{
			fCount++;
			if (fCount > 1 || i != temp.length() - 1)
				throw ScalarConverter::ImpossibleConversionException();
		}
		else if (!std::isdigit(temp[i]))
			throw ScalarConverter::ImpossibleConversionException();
	}

	if (fCount == 1)
	{
		doubleValue = strtod(temp.substr(0, temp.length() - 1).c_str(), NULL);
		return (1);
	}
	else if (dotCount == 1)
	{
		doubleValue = strtod(temp.c_str(), NULL);
		return (2);
	}
	else
	{
		doubleValue = strtod(temp.c_str(), NULL);
		return (3);
	}
}

void	ScalarConverter::convert(const std::string &str)
{
	double	doubleValue;

	try
	{
		checkType(str, doubleValue);
	}
	catch (std::exception &e)
	{
		throw;
	}

	std::cout << "char: ";
	if (std::isnan(doubleValue) || std::isinf(doubleValue) || doubleValue > 127 || doubleValue < 0)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(doubleValue)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(doubleValue) << "'" << std::endl;

	std::cout << "int: ";
	if (std::isnan(doubleValue) || std::isinf(doubleValue) || doubleValue > 2147483647 || doubleValue < -2147483648)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(doubleValue) << std::endl;

	std::cout << "float: ";
	if (doubleValue == 0)
		std::cout << "0.0f" << std::endl;
	else if (std::isnan(doubleValue))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(doubleValue))
	{
		if (doubleValue > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
	{
		float f = static_cast<float>(doubleValue);
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}

	std::cout << "double: ";
	if (doubleValue == 0)
		std::cout << "0.0" << std::endl;
	else if (std::isnan(doubleValue))
		std::cout << "nan" << std::endl;
	else if (std::isinf(doubleValue))
	{
		if (doubleValue > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}

const char	*ScalarConverter::ImpossibleConversionException::what(void) const throw()
{
	return ("Impossible conversion");
}

const char	*ScalarConverter::NonDisplayableException::what(void) const throw()
{
	return ("Non displayable");
}
