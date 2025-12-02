#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	std::cout << "=== Basic Construction ===" << std::endl;
	const Animal* a = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	std::cout << "\n=== Type Checking ===" << std::endl;
	std::cout << "Dog type: " << d->getType() << std::endl;
	std::cout << "Cat type: " << c->getType() << std::endl;
	std::cout << "Animal type: " << a->getType() << std::endl;

	std::cout << "\n=== Sound Tests (Polymorphism) ===" << std::endl;
	d->makeSound();
	c->makeSound();
	a->makeSound();

	std::cout << "\n=== Copy Constructor Test ===" << std::endl;
	Dog dog1;
	Dog dog2(dog1);      // Copy constructor
	dog2.makeSound();

	std::cout << "\n=== Copy Assignment Test ===" << std::endl;
	Dog dog3;
	dog3 = dog1;         // Assignment operator
	dog3.makeSound();

	std::cout << "\n=== Polymorphic Delete ===" << std::endl;
	delete a;
	delete d;
	delete c;

	std::cout << "\n=== End of tests ===" << std::endl;

	return (0);
}
