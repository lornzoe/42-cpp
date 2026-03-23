/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:11:11 by lyanga            #+#    #+#             */
/*   Updated: 2026/03/24 07:11:42 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Testing Serialization/Deserialization ===" << std::endl;

	std::cout << "\n--- Test 1: Create and Serialize Data ---" << std::endl;
	Data	*data = new Data();
	data->s1 = "Hello";
	data->n = 42;
	data->s2 = "World";

	std::cout << "Original Data:" << std::endl;
	std::cout << "  s1: " << data->s1 << std::endl;
	std::cout << "  n:  " << data->n << std::endl;
	std::cout << "  s2: " << data->s2 << std::endl;
	std::cout << "  ptr: " << data << std::endl;

	std::cout << "\n--- Test 2: Serialize Data Pointer ---" << std::endl;
	t_uintp	raw = Serializer::serialize(data);
	std::cout << "Serialized value: " << raw << std::endl;

	std::cout << "\n--- Test 3: Deserialize Back ---" << std::endl;
	Data	*deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "  s1: " << deserialized->s1 << std::endl;
	std::cout << "  n:  " << deserialized->n << std::endl;
	std::cout << "  s2: " << deserialized->s2 << std::endl;
	std::cout << "  ptr: " << deserialized << std::endl;

	std::cout << "\n--- Test 4: Verify Pointers Match ---" << std::endl;
	if (data == deserialized)
		std::cout << "SUCCESS: Pointers match!" << std::endl;
	else
		std::cout << "FAIL: Pointers don't match!" << std::endl;

	std::cout << "\n--- Test 5: Modify Deserialized Data ---" << std::endl;
	deserialized->s1 = "Goodbye";
	deserialized->n = 100;
	deserialized->s2 = "Universe";
	std::cout << "Modified Data:" << std::endl;
	std::cout << "  s1: " << data->s1 << std::endl;
	std::cout << "  n:  " << data->n << std::endl;
	std::cout << "  s2: " << data->s2 << std::endl;

	delete data;
	return (0);
}
