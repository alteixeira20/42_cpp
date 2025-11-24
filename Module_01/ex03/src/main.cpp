#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA	bruno("Bruno", club);
		bruno.attack();
		club.setType("some other type of club");
		bruno.attack();
	}
	{
		Weapon	sword = Weapon("sword");
		HumanB	aleixo("Aleixo");
		aleixo.attack();
		aleixo.setWeapon(sword);
		aleixo.attack();
		sword.setType("ice sword");
		aleixo.attack();
	}
	{
		Weapon	dagger = Weapon("dagger");
		HumanB	busto("Busto");
		busto.setWeapon(dagger);
		busto.attack();
		dagger.setType("poison dagger");
		busto.attack();
	}

}
