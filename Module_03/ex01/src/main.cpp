#include "ScavTrap.hpp"

/*
 * ex01 - ScavTrap
 *
 * This test program validates:
 *  - Basic ClapTrap behavior
 *  - ScavTrap inheritance
 *  - Method overriding (attack)
 *  - Shared base functionality (damage / repair)
 *  - ScavTrap-specific ability (guardGate)
 *  - Orthodox Canonical Form
 */
int	main(void)
{
	std::cout << "\n=== Construction ===\n" << std::endl;

	ClapTrap	basic("Basic");
	ScavTrap	guardian("Guardian");

	std::cout << "\n=== Attack behavior ===" << std::endl;
	std::cout << "Guardian attacks (expected: ScavTrap attack message)\n" << std::endl;
	guardian.attack("Enemy");

	std::cout << "\n=== Damage & repair ===" << std::endl;
	std::cout << "Guardian takes damage and repairs (expected: HP changes)\n" << std::endl;

	guardian.takeDamage(20);
	guardian.beRepaired(10);

	std::cout << "\nGuardian takes fatal damage (expected: destroyed)\n" << std::endl;
	guardian.takeDamage(200);

	std::cout << "\nGuardian tries to repair while destroyed (expected: failure)\n" << std::endl;
	guardian.beRepaired(5);

	std::cout << "\n=== ScavTrap special ability ===" << std::endl;
	std::cout << "Guardian activates Gate Keeper mode\n" << std::endl;
	guardian.guardGate();

	std::cout << "\n=== Copy constructor ===" << std::endl;
	std::cout << "Creating copy from Guardian (expected: same state)\n" << std::endl;
	ScavTrap	copyGuardian(guardian);

	std::cout << "\n=== Assignment operator ===" << std::endl;
	std::cout << "Assigning Guardian to new ScavTrap (expected: same state)\n" << std::endl;
	ScavTrap	assigned;
	assigned = guardian;

	std::cout << "\n=== End of program ===" << std::endl;
	std::cout << "Destructors will now be called\n" << std::endl;

	return (0);
}

