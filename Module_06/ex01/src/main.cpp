/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alteixeira20 <paalexan@student.42porto.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:12:52 by alteixeira20      #+#    #+#             */
/*   Updated: 2026/03/09 14:50:33 by alteixeira20     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

static void	printCase(const char *label, Data *ptr)
{
	uintptr_t	raw;
	Data		*back;

	std::cout << "=== " << label << " ===" << std::endl;
	std::cout << "original ptr: " << ptr << std::endl;

	raw = Serializer::serialize(ptr);
	std::cout << "serialized: " << raw << std::endl;

	back = Serializer::deserialize(raw);
	std::cout << "deserialized: " << back << std::endl;

	if (back == ptr)
		std::cout << "[OK] Pointers match!" << std::endl;
	else
		std::cout << "[KO] Pointers differ!" << std::endl;

	if (back != NULL)
		std::cout << "Value [n] = " << back->n << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	// Test stack object
	Data	stack;
	
	stack.n = 42;
	printCase("Stack Data", &stack);

	// Test heap object
	Data	*heap = new Data;
	heap->n = 1337;
	printCase("Heap Data (new)", heap);
	delete heap;

	// Test null pointer
	printCase("Null pointer", NULL);

	// Test showing that tampering with serialized ptr breaks it
	std::cout << "=== Tampered raw value ===" << std::endl;
	uintptr_t	raw_stack = Serializer::serialize(&stack);
	uintptr_t	tampered_raw = raw_stack + 1;
	Data		*fake = Serializer::deserialize(tampered_raw);

	std::cout << "raw_stack: " << raw_stack << std::endl;
	std::cout << "tampered_raw: " << tampered_raw << std::endl;
	std::cout << "deserialized ptr: " << fake << std::endl;
	std::cout << "[INFO] This pointer is not safe to dereference." << std::endl;
	return (0);
}
