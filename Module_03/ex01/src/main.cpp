#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "\n=== Constructing ClapTrap and ScavTrap ===\n" << std::endl;

    ClapTrap    basic("Basic");
    ScavTrap    guardian("Guardian");

    std::cout << "\n=== Testing ScavTrap Attack Override ===\n" << std::endl;

    guardian.attack("Enemy");

    std::cout << "\n=== Testing Damage and Repairs ===\n" << std::endl;

    guardian.takeDamage(20);
    guardian.beRepaired(10);
    guardian.takeDamage(200);    // Should destroy it
    guardian.beRepaired(5);      // Should fail (destroyed)

    std::cout << "\n=== Testing Gate Keeper Mode ===\n" << std::endl;

    guardian.guardGate();

    std::cout << "\n=== Testing Copy Constructor ===\n" << std::endl;

    ScavTrap copyGuardian(guardian);

    std::cout << "\n=== Testing Assignment Operator ===\n" << std::endl;

    ScavTrap assigned;
    assigned = guardian;

    std::cout << "\n=== End of main, destructors will now be called ===\n" << std::endl;

    return 0;
}

