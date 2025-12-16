#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Tester.hpp"

static void	test_full_pipeline(int count)
{
	test_polymorphism(count);
	test_deepcopy_dog();
	test_deepcopy_cat();
	test_wrong_polymorphism();
}

int	main(void)
{
	int	option;
	int	count;

	std::cout << "=== Animal Tester ===" << std::endl;
	std::cout << "1) Polymorphism test" << std::endl;
	std::cout << "2) Deep copy test (Dog)" << std::endl;
	std::cout << "3) Deep copy test (Cat)" << std::endl;
	std::cout << "4) Wrong Polymorphism test" << std::endl;
	std::cout << "5) Full pipeline" << std::endl;
	std::cout << "6) Exit" << std::endl;

	std::cout << "Choose option: ";
	std::cin >> option;

	if (option == 6)
		return 0;

	if (option != 4)
	{
		std::cout << "How many animals? ";
		std::cin >> count;
		if (count <= 0 || count > 100)
		{
			std::cout << "Number must be between 1 and 100" << std::endl;
			return 1;
		}
	}
	if (option == 1)
		test_polymorphism(count);
	else if (option == 2)
		test_deepcopy_dog();
	else if (option == 3)
		test_deepcopy_cat();
	else if (option == 4)
		test_wrong_polymorphism();
	else if (option == 5)
		test_full_pipeline(count);

	std::cout << "\n=== End of Tests ===" << std::endl;
	return 0;
}

