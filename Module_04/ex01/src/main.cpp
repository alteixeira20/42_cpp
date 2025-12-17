#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Tester.hpp"

int	main(void)
{
	const int	count = 6;

	std::cout << "=== Animal Tests ===" << std::endl;

	/*
	 * 1. Polymorphism through base pointers
	 *
+	 * Builds an array of Animals (half Dogs, half Cats), calls makeSound()
+	 * on each, and deletes via base pointers to verify virtual destructors.
	 */
	test_polymorphism(count);

	/*
	 * 2. Deep copy (Dog)
	 *
	 * Fills a Dog's Brain, copies it, mutates the copy, and confirms
	 * the original Brain stays unchanged after the copy dies.
	 */
	test_deepcopy_dog();

	/*
	 * 3. Deep copy (Cat)
	 *
	 * Mirrors the Dog test to ensure Cat also performs deep copies
	 * of its Brain storage.
	 */
	test_deepcopy_cat();

	std::cout << "\n=== End of Tests ===" << std::endl;
	return (0);
}
