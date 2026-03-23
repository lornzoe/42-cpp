/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:11:19 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:11:42 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &src) { (void)src; }

Serializer::~Serializer(void) {}

Serializer	&Serializer::operator=(const Serializer &rhs)
{
	(void)rhs;
	return (*this);
}

t_uintp	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<t_uintp>(ptr));
}

Data	*Serializer::deserialize(t_uintp raw)
{
	return (reinterpret_cast<Data *>(raw));
}
