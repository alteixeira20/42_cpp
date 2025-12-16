#include "DiamondTrap.hpp"
#include <iostream>

/* Prints a formatted section header. */
static void section(const std::string &title)
{
	std::cout << "\n=== " << title << " ===\n" << std::endl;
}

/* Prints a simple visual separator. */
static void separator()
{
	std::cout << "----------------------------------------" << std::endl;
}

int main(void)
{
	/*
	 * 1. Construction
	 *
	 * Validates:
	 *  - Correct constructor chain
	 *  - Proper initialization of names
	 *  - Correct stat inheritance
	 */
	section("Creating DiamondTrap");
	DiamondTrap d("Diamond");
	separator();

	/*
	 * 2. Identity Test
	 *
	 * Expected output:
	 *   My DiamondTrap name is Diamond
	 *   and my ClapTrap name is Diamond_clap_name
	 *
	 * Confirms separate identity storage.
	 */
	section("whoAmI() identity check");
	d.whoAmI();
	separator();

	/*
	 * 3. Attack Method Resolution
	 *
	 * DiamondTrap must use ScavTrap::attack().
	 * Output should clearly identify ScavTrap behavior.
	 */
	section("Attack uses ScavTrap::attack");
	d.attack("Target Dummy");
	separator();

	/*
	 * 4. HP & EP Behavior
	 *
	 * Expected flow:
	 *   HP: 120 -> 100 -> 110 -> 0
	 *   Repair after death must fail.
	 */
	section("Damage & repair logic");
	d.takeDamage(20);
	d.beRepaired(10);
	d.takeDamage(200);
	d.beRepaired(5);
	separator();

	/*
	 * 5. FragTrap Ability
	 *
	 * Confirms FragTrap inheritance.
	 */
	section("FragTrap special ability");
	d.highFivesGuys();
	separator();

	/*
	 * 6. ScavTrap Ability
	 *
	 * Confirms ScavTrap inheritance.
	 */
	section("ScavTrap special ability");
	d.guardGate();
	separator();

	/*
	 * 7. Copy Constructor
	 *
	 * Confirms deep copy and correct constructor chain.
	 */
	section("Copy constructor");
	DiamondTrap copy(d);
	copy.whoAmI();
	separator();

	/*
	 * 8. Assignment Operator
	 *
	 * Confirms correct operator= behavior.
	 */
	section("Assignment operator");
	DiamondTrap assigned;
	assigned = d;
	assigned.whoAmI();
	separator();

	/*
	 * 9. Energy Depletion Stress Test
	 *
	 * DiamondTrap uses ScavTrap energy (50 EP).
	 * Attacks must stop cleanly at 0 EP.
	 */
	section("Energy depletion test");
	DiamondTrap battery("Battery");
	while (battery.getEnergyPoints() > 0)
		battery.attack("Training Dummy");
	battery.attack("After exhaustion");
	battery.attack("After exhaustion");
	separator();

	/*
	 * 10. Destructor Order
	 *
	 * Expected order:
	 *   DiamondTrap
	 *   FragTrap
	 *   ScavTrap
	 *   ClapTrap
	 */
	section("End of program");

	return 0;
}
