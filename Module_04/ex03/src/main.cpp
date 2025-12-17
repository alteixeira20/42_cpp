#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

static void	printTitle(const std::string &title)
{
	std::cout << "\n== " << title << " ===\n" << std::endl;
}

int main()
{
	/*
	 * 1. MateriaSource setup
	 *
	 * Learn two materias (ice, cure) to seed the factory.
	 */
	printTitle("1) Creating MateriaSource and learning materias");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	printTitle("2) Creating characters");

	ICharacter* me = new Character("player");
	ICharacter* bob = new Character("bob");

	/*
	 * 2. Create + equip materia
	 *
	 * Clone from the source and equip into the first free slots.
	 */
	printTitle("3) Creating materia from source");

	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	printTitle("4) Using materia");

	me->use(0, *bob); // ice
	me->use(1, *bob); // cure

	/*
	 * 3. Inventory limit
	 *
	 * Fill all four slots, then try a fifth (should no-op).
	 */
	printTitle("5) Inventory limit test");

	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));

	// This one should NOT fit (inventory is full)
	me->equip(src->createMateria("ice"));

	/*
	 * 4. Unequip behavior
	 *
	 * Unequip must not delete; using the empty slot should do nothing.
	 */
	printTitle("6) Unequip test");

	me->unequip(0); // should NOT delete materia
	me->use(0, *bob); // should do nothing

	/*
	 * 5. Deep copy
	 *
	 * Copy a character with equipment, mutate the copy, and
	 * confirm the original stays intact.
	 */
	printTitle("7) Deep copy of character");

	Character* real = new Character("original");
	real->equip(new Ice());
	real->equip(new Cure());

	Character copy(*real); // copy constructor

	printTitle("8) Modifying copy should NOT affect original");

	// Modify copy's inventory
	copy.equip(new Ice()); // equip new materia
	copy.use(0, *bob);

	// Ensure real is unaffected
	real->use(0, *bob);

	/*
	 * 6. Cleanup
	 *
	 * Delete everything and rely on virtual destructors to
	 * release inventories and learned materia.
	 */
	printTitle("9) Cleaning memory");

	delete bob;
	delete me;
	delete src;
	delete real;

	std::cout << "\n=== END OF TESTS ===\n" << std::endl;

	return (0);
}
