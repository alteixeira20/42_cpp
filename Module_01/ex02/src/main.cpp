#include <iostream>

int	main(void)
{
	// A string VAR stored on the stack.
	//	- It's a real object that holds the text.
	std::string	stringVAR = "HI THIS IS BRAIN";

	// A POINTER to a string
	//	- Stores the MEM ADDRESS of stringVAR.
	//	- Must DEREFERENCE using '*' to access the Value
	//	- Can be NULL and can be changed to point elsewhere
	std::string*	stringPTR = &stringVAR;

	// A REFERENCE to a string (it is an alias for stringVAR)
	// 	- Can't be NULL.
	// 	- Must be initialized immediately.
	// 	- No need to dereference.
	std::string&	stringREF = stringVAR;

	// Print memory addresses
	//	- stringVAR is the actual variable
	//	- stringPTR holds its address
	//	- stringREF is an alias for the same variable
	std::cout << "Address of stringVAR: " << &stringVAR << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;

	// Print Values
	// 	- stringVAR stores the actual text
	// 	- *stringPTR dereferences the pointer to get the text
	// 	- stringREF is the text itself (alias)
	std::cout << "Value of stringVAR: " << stringVAR << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value referenced by stringREF: " << stringREF << std::endl;

	return (0);
}
