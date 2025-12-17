#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	/*
	 * 1. Basic Construction
	 *
	 * Creates one Animal, one Dog, and one Cat using base-class
	 * pointers to test polymorphic behavior.
	 */
	std::cout << "=== Basic Construction ===" << std::endl;
	const Animal* a = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	/*
	 * 2. Type Identification
	 *
	 * Verifies that each object reports the correct type.
	 */
	std::cout << "\n=== Type Checking ===" << std::endl;
	std::cout << "Dog type: " << d->getType() << std::endl;
	std::cout << "Cat type: " << c->getType() << std::endl;
	std::cout << "Animal type: " << a->getType() << std::endl;

	/*
	 * 3. Polymorphic Sound Test
	 *
	 * Ensures that makeSound() is dispatched dynamically based on
	 * the actual object type, not the pointer type.
	 */
	std::cout << "\n=== Sound Tests (Polymorphism) ===" << std::endl;
	d->makeSound();
	c->makeSound();
	a->makeSound();

	/*
	 * 4. Copy Constructor Test
	 *
	 * Validates correct copy construction and independence.
	 */
	std::cout << "\n=== Copy Constructor Test ===" << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	dog2.makeSound();

	/*
	 * 5. Copy Assignment Operator Test
	 *
	 * Validates correct assignment behavior.
	 */
	std::cout << "\n=== Copy Assignment Test ===" << std::endl;
	Dog dog3;
	dog3 = dog1;
	dog3.makeSound();

	/*
	 * 6. Polymorphic Deletion
	 *
	 * Ensures that destructors are called correctly through
	 * base-class pointers (virtual destructor test).
	 */
	std::cout << "\n=== Polymorphic Delete ===" << std::endl;
	delete a;
	delete d;
	delete c;

	std::cout << "\n=== End of tests ===" << std::endl;

	return (0);
}
