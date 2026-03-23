/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:11:22 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:11:42 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

typedef uintptr_t	t_uintp;

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer &src);
	~Serializer(void);
	Serializer	&operator=(const Serializer &rhs);

public:
	static t_uintp	serialize(Data *ptr);
	static Data		*deserialize(t_uintp raw);
};

#endif
