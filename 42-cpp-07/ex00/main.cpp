/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:12:31 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/26 12:56:02 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void )
{
	int a = 2;
	int b = 3;
	std::cout << "a = " << a << "(" << &a << ")" << ", b = " << b << "(" << &b << ")" << std::endl;
	swap( a, b );
	std::cout << "swap( a, b )" << std::endl;
	std::cout << "a = " << a << "(" << &a << ")" << ", b = " << b << "(" << &b << ")" << std::endl;
	std::cout << "min( a, b ) = " << min( a, b ) << &min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max( a, b ) << &max(a, b) << std::endl;
	a = 2; // equal case
	std::cout << "a = " << a << "(" << &a << ")" << ", b = " << b << "(" << &b << ")" << std::endl;
	std::cout << "min( a, b ) = " << min( a, b ) << " " << &min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max( a, b ) << " " << &max(a, b) << std::endl;

	// trying with other types
	std::string c = "chaine1";
	std::string d = "chaine23";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "swap( c, d )" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << max( c, d ) << std::endl;
	return 0;
}