#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;           // Default constructor
	Fixed b(a);        // Copy constructor
	Fixed c;           // Default constructor

	c = b;             // Copy assignment operator

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// --- Extra tests for setRawBits() ---
	std::cout << "\n--- Testing setRawBits() ---" << std::endl;

	a.setRawBits(42);  
	b.setRawBits(99);

	std::cout << "a raw bits = " << a.getRawBits() << std::endl;
	std::cout << "b raw bits = " << b.getRawBits() << std::endl;

	// Test that changing a does NOT change c
	std::cout << "c raw bits (should still be 0) = " << c.getRawBits() << std::endl;

	return 0;
}
