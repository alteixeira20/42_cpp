#include "ClapTrap.hpp"

/*
 * ex00 - ClapTrap
 *
 * This test program validates:
 *  - construction and destruction
 *  - attacking and energy consumption
 *  - taking damage and death conditions
 *  - repair limitations
 *  - copy and assignment semantics
 */
int main(void)
{
	std::cout << "\n=== Construction ===" << std::endl;
	ClapTrap	a("Tom");
	ClapTrap	b("Jerry");

	std::cout << "\n=== Attack & Damage ===" << std::endl;
	std::cout << "Tom attacks Jerry (expected: attack succeeds)" << std::endl;
	a.attack("Jerry");

	std::cout << "Jerry takes 5 damage (expected: HP reduced)" << std::endl;
	b.takeDamage(5);

	std::cout << "Jerry takes 10 damage (expected: HP reaches 0)" << std::endl;
	b.takeDamage(10);

	std::cout << "Jerry takes damage again (expected: already destroyed)" << std::endl;
	b.takeDamage(1);

	std::cout << "\n=== Repair ===" << std::endl;
	std::cout << "Tom repairs himself (expected: HP increases, EP decreases)" << std::endl;
	a.beRepaired(3);

	std::cout << "Jerry tries to repair (expected: cannot repair, destroyed)" << std::endl;
	b.beRepaired(5);

	std::cout << "\n=== Energy Depletion ===" << std::endl;
	ClapTrap	c("Charlie");

	std::cout << "Charlie attacks until energy is depleted (expected: attacks stop)" << std::endl;
	for (int i = 0; i < 12; i++)
		c.attack("Dummy");

	std::cout << "\n=== Copy Constructor ===" << std::endl;
	ClapTrap	copy(a);
	std::cout << "Copy constructed from Tom (expected: same state)" << std::endl;

	std::cout << "\n=== Assignment Operator ===" << std::endl;
	ClapTrap	assigned;
	assigned = b;
	std::cout << "Assigned from Jerry (expected: destroyed state copied)" << std::endl;

	std::cout << "\n=== End of Program ===" << std::endl;
	std::cout << "Destructors will now be called" << std::endl;

	return (0);}
