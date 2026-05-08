/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:10:34 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/08 04:21:39 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,
    INVALID
};

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

static void printConverted(char c, int i, float f, double d, bool isSpecial)
{
    std::cout << "char: ";
    if (isSpecial || i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    std::cout << "int: ";
    if (isSpecial || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

static void	printSpecial(const std::string &str)
{
    std::string base;

    if (str == "nan" || str == "nanf")
        base = "nan";
    else if (str == "+inf" || str == "+inff")
        base = "+inf";
    else if (str == "-inf" || str == "-inff")
        base = "-inf";

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << base << "f" << std::endl;
	std::cout << "double: " << base << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    double d = 0;
    char *endptr = NULL;
    
    e_type type = INVALID;

    if (str.length() == 1 && !std::isdigit(str[0])) 
        type = CHAR;
    else 
	{
        d = std::strtod(str.c_str(), &endptr);
        
        if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
            type = SPECIAL;
        else if (*endptr == '\0')
            type = (str.find('.') == std::string::npos) ? INT : DOUBLE;
        else if (*endptr == 'f' && *(endptr + 1) == '\0')
            type = FLOAT;
    }

    switch (type) {
        case CHAR: 
		{
            char c = str[0];
            printConverted(static_cast<char>(c), static_cast<int>(c), 
                           static_cast<float>(c), static_cast<double>(c), false);
            break;
        }
        case INT:
		{
            if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
			{
                printSpecial("impossible");
                return;
            }
            int i = static_cast<int>(d);
            printConverted(static_cast<char>(i), i, 
                           static_cast<float>(i), static_cast<double>(i), false);
            break;
        }
        case FLOAT:
		{
            float f = static_cast<float>(d);
            printConverted(static_cast<char>(f), static_cast<int>(f), 
                           f, static_cast<double>(f), false);
            break;
        }
        case DOUBLE:
            printConverted(static_cast<char>(d), static_cast<int>(d), 
                           static_cast<float>(d), d, false);
            break;
        case SPECIAL:
            printSpecial(str);
            break;
        default:
            std::cout << "Error: Invalid input format." << std::endl;
    }
}

const char	*ScalarConverter::ImpossibleConversionException::what(void) const throw()
{
	return ("Impossible conversion");
}

const char	*ScalarConverter::NonDisplayableException::what(void) const throw()
{
	return ("Non displayable");
}
