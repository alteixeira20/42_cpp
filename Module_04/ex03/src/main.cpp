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
	/* ============================================================
	   1. BASIC MATERIA SOURCE TEST
	============================================================ */
	printTitle("Creating MateriaSource and learning materias");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	printTitle("Creating characters");

	ICharacter* me = new Character("player");
	ICharacter* bob = new Character("bob");

	/* ============================================================
	   2. CREATING MATERIA AND EQUIPPING
	============================================================ */
	printTitle("Creating materia from source");

	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	printTitle("Using materia");

	me->use(0, *bob); // ice
	me->use(1, *bob); // cure

	/* ============================================================
	   3. INVENTORY LIMIT TEST
	============================================================ */
	printTitle("Inventory limit test");

	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));

	// This one should NOT fit (inventory is full)
	me->equip(src->createMateria("ice"));

	/* ============================================================
	   4. UNEQUIP TEST
	============================================================ */
	printTitle("Unequip test");

	me->unequip(0); // should NOT delete materia
	me->use(0, *bob); // should do nothing

	/* ============================================================
	   5. DEEP COPY TEST
	============================================================ */
	printTitle("Deep copy of character");

	Character* real = new Character("original");
	real->equip(new Ice());
	real->equip(new Cure());

	Character copy(*real); // copy constructor

	printTitle("Modifying copy should NOT affect original");

	// Modify copy's inventory
	copy.equip(new Ice()); // equip new materia
	copy.use(0, *bob);

	// Ensure real is unaffected
	real->use(0, *bob);

	/* ============================================================
	   6. CLEANUP TEST
	============================================================ */
	printTitle("Cleaning memory");

	delete bob;
	delete me;
	delete src;
	delete real;

	std::cout << "\n=== END OF TESTS ===\n" << std::endl;

	return (0);
}
