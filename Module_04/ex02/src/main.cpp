#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Tester.hpp"

int	main(void)
{
	const int	count = 6;

	std::cout << "=== Animal Tests (Abstract Base) ===" << std::endl;

	/*
	 * 1. Polymorphism through abstract base pointers
	 *
+	 * Builds an array of Animals (half Dogs, half Cats), calls makeSound()
+	 * on each, and deletes via base pointers to verify virtual destructors.
	 */
	test_polymorphism(count);

	/*
	 * 2. Deep copy (Dog)
	 *
	 * Confirms Dog owns its Brain deeply across copy construction and scope exit.
	 */
	test_deepcopy_dog();

	/*
	 * 3. Deep copy (Cat)
	 *
	 * Same deep-copy verification for Cat.
	 */
	test_deepcopy_cat();

	/*
	 * 4. Wrong hierarchy (no virtuals)
	 *
	 * Demonstrates that replacing Animal/Cat with WrongAnimal/WrongCat
	 * produces static binding (WrongAnimal sound).
	 */
	test_wrong_polymorphism();

	std::cout << "\n=== End of Tests ===" << std::endl;
	return (0);
}
