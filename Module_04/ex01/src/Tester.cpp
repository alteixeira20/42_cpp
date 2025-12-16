#include "Tester.hpp"

static void	print_idea(const std::string &label, const std::string &idea)
{
	std::cout << label << idea << std::endl;
}

static void	fill_brain(Brain *brain, const std::string &base)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		brain->setIdea(i, base);
		i++;
	}
}

void	test_deepcopy_dog(void)
{
	Dog	basic;

	std::cout << "\n=== Deep Copy Test (Dog) ===\n" << std::endl;

	fill_brain(basic.getBrain(), "Dog Original");

	print_idea("basic idea[0]: ", basic.getBrain()->getIdea(0));
	print_idea("basic idea[10]: ", basic.getBrain()->getIdea(10));
	print_idea("basic idea[42]: ", basic.getBrain()->getIdea(42));
	print_idea("basic idea[99]: ", basic.getBrain()->getIdea(99));

	std::cout << "\n--- Creating tmp (copy of basic) ---" << std::endl;
	{
		Dog tmp = basic;

		tmp.getBrain()->setIdea(0, "Dog COPY #0");
		tmp.getBrain()->setIdea(10, "Dog COPY #10");
		tmp.getBrain()->setIdea(42, "Dog COPY #42");
		tmp.getBrain()->setIdea(99, "Dog COPY #99");

		std::cout << "Inside scope:" << std::endl;
		print_idea("	basic idea[0]: ", basic.getBrain()->getIdea(0));
		print_idea("	tmp   idea[0]: ", tmp.getBrain()->getIdea(0));

		print_idea("	basic idea[10]: ", basic.getBrain()->getIdea(10));
		print_idea("	tmp   idea[10]: ", tmp.getBrain()->getIdea(10));

		print_idea("	basic idea[42]: ", basic.getBrain()->getIdea(42));
		print_idea("	tmp   idea[42]: ", tmp.getBrain()->getIdea(42));

		print_idea("	basic idea[99]: ", basic.getBrain()->getIdea(99));
		print_idea("	tmp   idea[99]: ", tmp.getBrain()->getIdea(99));
	}

	std::cout << "\nAfter tmp is destroyed:" << std::endl;
	print_idea("  basic idea[0]: ", basic.getBrain()->getIdea(0));
	print_idea("  basic idea[10]: ", basic.getBrain()->getIdea(10));
	print_idea("  basic idea[42]: ", basic.getBrain()->getIdea(42));
	print_idea("  basic idea[99]: ", basic.getBrain()->getIdea(99));
}

void	test_deepcopy_cat(void)
{
	Cat	basic;

	std::cout << "\n=== Deep Copy Test (Cat) ===" << std::endl;

	fill_brain(basic.getBrain(), "Cat Original");

	print_idea("basic idea[0]: ", basic.getBrain()->getIdea(0));
	print_idea("basic idea[10]: ", basic.getBrain()->getIdea(10));
	print_idea("basic idea[42]: ", basic.getBrain()->getIdea(42));
	print_idea("basic idea[99]: ", basic.getBrain()->getIdea(99));

	std::cout << "\n--- Creating tmp (copy of basic) ---" << std::endl;
	{
		Cat tmp = basic;

		tmp.getBrain()->setIdea(0, "Cat COPY #0");
		tmp.getBrain()->setIdea(10, "Cat COPY #10");
		tmp.getBrain()->setIdea(42, "Cat COPY #42");
		tmp.getBrain()->setIdea(99, "Cat COPY #99");

		std::cout << "Inside scope:" << std::endl;
		print_idea("	basic idea[0]: ", basic.getBrain()->getIdea(0));
		print_idea("	tmp   idea[0]: ", tmp.getBrain()->getIdea(0));

		print_idea("	basic idea[10]: ", basic.getBrain()->getIdea(10));
		print_idea("	tmp   idea[10]: ", tmp.getBrain()->getIdea(10));

		print_idea("	basic idea[42]: ", basic.getBrain()->getIdea(42));
		print_idea("	tmp   idea[42]: ", tmp.getBrain()->getIdea(42));

		print_idea("	basic idea[99]: ", basic.getBrain()->getIdea(99));
		print_idea("	tmp   idea[99]: ", tmp.getBrain()->getIdea(99));
	}

	std::cout << "\nAfter tmp is destroyed:" << std::endl;
	print_idea("  basic idea[0]: ", basic.getBrain()->getIdea(0));
	print_idea("  basic idea[10]: ", basic.getBrain()->getIdea(10));
	print_idea("  basic idea[42]: ", basic.getBrain()->getIdea(42));
	print_idea("  basic idea[99]: ", basic.getBrain()->getIdea(99));
}

static void	create_animal_array(Animal **animals, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		i++;
	}
}

void	test_polymorphism(int count)
{
	Animal	**animals;
	int	i;

	std::cout << "\n=== Testing Polymorphism ===\n" << std::endl;

	std::cout << "--- Creating Animal Array ---" << std::endl;
	animals = new Animal*[count];
	create_animal_array(animals, count);
	std::cout << "\n-- Testing Sounds Produced ---" << std::endl;
	i = 0;
	while (i < count)
	{
		animals[i]->makeSound();
		i++;
	}

	std::cout << "\n-- Deleting Animals ---" << std::endl;
	i = 0;
	while (i < count)
	{
		delete animals[i];
		i++;
	}
	delete [] animals;
}
