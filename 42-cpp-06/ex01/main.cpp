/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:11:11 by lyanga            #+#    #+#             */
/*   Updated: 2026/05/08 10:35:50 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	std::cout << std::endl << "--- create and serialise data ---" << std::endl;
	Data	*data = new Data();
	data->s1 = "Hello";
	data->n = 42;
	data->s2 = "World";

	std::cout << "(orig) data:" << std::endl;
	std::cout << "  s1: " << data->s1 << std::endl;
	std::cout << "  n:  " << data->n << std::endl;
	std::cout << "  s2: " << data->s2 << std::endl;
	std::cout << "  ptr: " << data << std::endl;

	std::cout << std::endl << "--- serialise data ---" << std::endl;
	uintptr_t	raw = Serializer::serialize(data);
	std::cout << "serialized value: " << raw << std::endl;
	std::cout << "serialised value as hex val: " << std::hex << raw << std::dec << std::endl;
	
	std::cout << std::endl << "--- deserialise data ---" << std::endl;
	Data	*deserialized = Serializer::deserialize(raw);
	std::cout << "deserialised data:" << std::endl;
	std::cout << "  s1: " << deserialized->s1 << std::endl;
	std::cout << "  n:  " << deserialized->n << std::endl;
	std::cout << "  s2: " << deserialized->s2 << std::endl;
	std::cout << "  ptr: " << deserialized << std::endl;

	if (data == deserialized)
		std::cout << "-- pointers match" << std::endl;
	else
		std::cout << "-- pointers DON'T match" << std::endl;

	delete data;
	return (0);
}
