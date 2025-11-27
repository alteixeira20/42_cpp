#include "FragTrap.hpp"

int	main()
{
	std::cout << "\n=== Creating FragTrap ===\n" << std::endl;
	FragTrap f("Rocky");

	std::cout << "\n=== Testing Attack ===\n" << std::endl;
	f.attack("Target Dummy");

	std::cout << "\n=== Testing High Five ===\n" << std::endl;
	f.highFivesGuys();

	std::cout << "\n=== Testing Damage and Repair ===\n" << std::endl;
	f.takeDamage(20);
	f.beRepaired(10);
	f.takeDamage(200);

	std::cout << "\n=== Copy & Assignment ===\n" << std::endl;
	FragTrap copy(f);
	FragTrap assigned;
	assigned = f;

	std::cout << "\n=== End of main, destructors ===\n" << std::endl;

	return (0);
}
