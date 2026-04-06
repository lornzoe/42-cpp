/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:11:27 by lyanga            #+#    #+#             */
/*   Updated: 2026/04/06 19:24:52 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
public:
	Base(void) {}
	virtual ~Base(void) {}
};

class A : public Base
{
public:
	A(void) {}
	virtual ~A(void) {}
};

class B : public Base
{
public:
	B(void) {}
	virtual ~B(void) {}
};

class C : public Base
{
public:
	C(void) {}
	virtual ~C(void) {}
};

#endif
