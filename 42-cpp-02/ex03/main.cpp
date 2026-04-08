/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 06:55:14 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/08 19:45:36 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void) {
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	Point p1(5, 5);   // Inside
	Point p2(1, 1);   // Inside
	Point p3(10, 1);  // Outside
	Point p4(5, 0);   // On edge
	Point p5(0, 0);   // On vertex

	std::cout << "Point p1 is " << (bsp(a, b, c, p1) ? "inside" : "outside") << std::endl;
	std::cout << "Point p2 is " << (bsp(a, b, c, p2) ? "inside" : "outside") << std::endl;
	std::cout << "Point p3 is " << (bsp(a, b, c, p3) ? "inside" : "outside") << std::endl;
	std::cout << "Point p4 is " << (bsp(a, b, c, p4) ? "inside" : "outside") << std::endl;
	std::cout << "Point p5 is " << (bsp(a, b, c, p5) ? "inside" : "outside") << std::endl;

	Point d(0.0f, 0.0f);
	Point e(10.f, 0.f);
	Point f(5.f, 10.f);
	
	Point p6(5.f, 10.f); // On vertex
	Point p7(0.0f, 0.1f); // Outside
	Point p8(0.01f, 0.01f); // Inside

	std::cout << "Point p6 is " << (bsp(d, e, f, p6) ? "inside" : "outside") << std::endl;
	std::cout << "Point p7 is " << (bsp(d, e, f, p7) ? "inside" : "outside") << std::endl;
	std::cout << "Point p8 is " << (bsp(d, e, f, p8) ? "inside" : "outside") << std::endl;

	return 0;
}