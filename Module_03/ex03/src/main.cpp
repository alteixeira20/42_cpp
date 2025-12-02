#include "DiamondTrap.hpp"

#include "DiamondTrap.hpp"

int main(void)
{
	// ------------------------------------------------------------
	// 1. Construction
	// ------------------------------------------------------------
	// This test validates:
	//  - Correct constructor chain order: ClapTrap → ScavTrap → FragTrap → DiamondTrap
	//  - Correct initialization of names ("Diamond" and "Diamond_clap_name")
	//  - Correct stat inheritance (FragTrap HP & AD, ScavTrap EP)
	// ------------------------------------------------------------
	std::cout << "\n=== Creating DiamondTrap ===\n" << std::endl;
	DiamondTrap d("Diamond");


	// ------------------------------------------------------------
	// 2. Identity Test (whoAmI)
	// ------------------------------------------------------------
	// Expected:
	//   My DiamondTrap name is Diamond
	//   and my ClapTrap name is Diamond_clap_name
	//
	// This proves that:
	//  - DiamondTrap has its own _name
	//  - ClapTrap::_name was properly initialized separately
	// ------------------------------------------------------------
	std::cout << "\n=== Testing whoAmI() ===\n" << std::endl;
	d.whoAmI();


	// ------------------------------------------------------------
	// 3. Attack Method Override
	// ------------------------------------------------------------
	// DiamondTrap must use **ScavTrap::attack** (NOT FragTrap::attack).
	// Expected output begins with:
	//   ScavTrap <name> ferociously attacks ...
	//
	// Confirms correct method resolution order (MRO).
	// ------------------------------------------------------------
	std::cout << "\n=== Testing Attack (Should use ScavTrap::attack) ===\n" << std::endl;
	d.attack("Target Dummy");


	// ------------------------------------------------------------
	// 4. HP & EP Logic
	// ------------------------------------------------------------
	// Tests:
	//   - Taking normal damage
	//   - Repairing when alive
	//   - Taking fatal damage (drops to 0 HP)
	//   - Repairing when dead (should NOT work)
	//
	// This confirms correct state-based behavior.
	// ------------------------------------------------------------
	std::cout << "\n=== Testing Damage & Repairs ===\n" << std::endl;
	d.takeDamage(20);     // HP: 120 → 100
	d.beRepaired(10);     // HP: 100 → 110
	d.takeDamage(200);    // HP: 110 → 0 (death)
	d.beRepaired(5);      // Should fail (HP = 0)


	// ------------------------------------------------------------
	// 5. FragTrap Special Ability
	// ------------------------------------------------------------
	// FragTrap gives DiamondTrap the method highFivesGuys().
	// Expected:
	//   FragTrap <name> requests a high five! ✋
	// ------------------------------------------------------------
	std::cout << "\n=== Testing FragTrap High Five ===\n" << std::endl;
	d.highFivesGuys();


	// ------------------------------------------------------------
	// 6. ScavTrap Special Ability
	// ------------------------------------------------------------
	// DiamondTrap inherits guardGate() from ScavTrap.
	// Expected:
	//   ScavTrap <name> has entered Gate keeper mode!
	// ------------------------------------------------------------
	std::cout << "\n=== Testing ScavTrap Guard Gate ===\n" << std::endl;
	d.guardGate();


	// ------------------------------------------------------------
	// 7. Copy Constructor
	// ------------------------------------------------------------
	// Tests:
	//   - Correct copy constructor chain (ClapTrap, ScavTrap, FragTrap, DiamondTrap)
	//   - Correct deep-copy of DiamondTrap's own name
	//   - Copy performs independent behavior afterwards
	// ------------------------------------------------------------
	std::cout << "\n=== Testing Copy Constructor ===\n" << std::endl;
	DiamondTrap copy(d);
	copy.whoAmI();


	// ------------------------------------------------------------
	// 8. Assignment Operator
	// ------------------------------------------------------------
	// Tests:
	//   - Default-constructed DiamondTrap is overwritten with d's data
	//   - Correct operator= resolution through the inheritance chain
	//   - After assignment, names & stats match the source object
	// ------------------------------------------------------------
	std::cout << "\n=== Testing Assignment Operator ===\n" << std::endl;
	DiamondTrap assigned;
	assigned = d;
	assigned.whoAmI();

	// ------------------------------------------------------------
	// 9. Energy Points Depletion Test
	// ------------------------------------------------------------
	// DiamondTrap starts with ScavTrap’s EP = 50.
	//
	// This loop repeatedly calls attack() until EP reaches 0.
	// Expected behavior:
	//   - First 50 attacks decrease EP normally
	//   - When EP becomes 0, further attacks should print:
	//       "ClapTrap <name> has no energy to attack!"
	//
	// This confirms:
	//   - EP decreases correctly
	//   - EP cannot go negative
	//   - State-based behavior works under stress testing
	// ------------------------------------------------------------
	std::cout << "\n=== Testing Energy Depletion ===\n" << std::endl;

	DiamondTrap epTest("Battery");

	// Burn all EP
	while (true)
	{
		epTest.attack("Training Dummy");

		// Stop when we observe the “no energy” message
		if (epTest.getEnergyPoints() == 0)
			break;
	}

	// Try a few extra attacks to verify it refuses properly
	epTest.attack("Dummy After Exhaustion");
	epTest.attack("Dummy After Exhaustion");


	// ------------------------------------------------------------
	// 10. Destructor Order
	// ------------------------------------------------------------
	// Expected destructor order on exit:
	//   DiamondTrap → FragTrap → ScavTrap → ClapTrap
	//
	// This proves:
	//   - Correct virtual destructor behavior
	//   - Proper diamond inheritance cleanup
	// ------------------------------------------------------------
	std::cout << "\n=== End of main, destructors will now run ===\n" << std::endl;

	return 0;
}
