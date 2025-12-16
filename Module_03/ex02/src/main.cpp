#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "\n=== Construction ===\n" << std::endl;

	FragTrap	f("Rocky");

	std::cout << "\n=== Initial Stats Check ===\n" << std::endl;
	std::cout << "Expected: HP = 120, EP = 100, AD = 30\n" << std::endl;

	std::cout << "\n=== Attack behavior (FragTrap stats) ===\n" << std::endl;
	std::cout << "Expected: 30 damage, EP decreases from 100\n" << std::endl;

	f.attack("Target Dummy");
	f.attack("Target Dummy");

	std::cout << "\n=== Special ability ===\n" << std::endl;

	f.highFivesGuys();

	std::cout << "\n=== Damage & repair ===\n" << std::endl;
	std::cout << "Expected: HP goes from 120 -> 100 -> 110\n" << std::endl;

	f.takeDamage(20);
	f.beRepaired(10);

	std::cout << "\n=== Destruction check ===\n" << std::endl;
	std::cout << "Expected: FragTrap becomes destroyed\n" << std::endl;

	f.takeDamage(200);
	f.beRepaired(5);

	std::cout << "\n=== Copy constructor ===\n" << std::endl;
	std::cout << "Expected: copied FragTrap has same stats\n" << std::endl;

	FragTrap	copy(f);

	std::cout << "\n=== Assignment operator ===\n" << std::endl;
	std::cout << "Expected: assigned FragTrap has same stats\n" << std::endl;

	FragTrap	assigned;
	assigned = f;

	std::cout << "\n=== End of main ===\n" << std::endl;

	return (0);
}
