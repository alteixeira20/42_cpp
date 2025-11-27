#include "ClapTrap.hpp"

int main(void)
{
	int	i = 0;

	std::cout << "\n=== Constructing ClapTraps ===\n";
	ClapTrap a("Tom");
	ClapTrap b("Jerry");

	std::cout << "\n=== Testing Attacks ===\n";
	a.attack("Jerry");
	b.takeDamage(0); // No damage, but message still shows

	std::cout << "\n=== Testing Damage ===\n";
	b.takeDamage(5);
	b.takeDamage(10); // should drop HP to 0
	b.takeDamage(1);  // should say "already destroyed"

	std::cout << "\n=== Testing Repairs ===\n";
	a.beRepaired(3);  // valid repair
	b.beRepaired(5);  // cannot repair (destroyed)

	std::cout << "\n=== Testing Energy Depletion ===\n";
	ClapTrap c("Charlie");
	while (i < 12)
	{
		c.attack("Dummy");  // after 10 EP, attacks should fail
		i++;
	}
	std::cout << "\n=== Testing Copy Constructor ===\n";
	ClapTrap copy(a);

	std::cout << "\n=== Testing Assignment Operator ===\n";
	ClapTrap assigned;
	assigned = b;

	std::cout << "\n=== End of main, destructors called ===\n\n";
	return 0;
}
