#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");
	ICharacter* you = new Character("you");
	ICharacter* bob = new Character("bob");

	AMateria* ice = src->createMateria("ice");
	AMateria* cure0 = src->createMateria("cure");
	AMateria* cure1 = src->createMateria("cure");
	AMateria* cure2 = src->createMateria("cure");

	me->equip(ice);
	me->equip(cure0);
	me->equip(cure1);
	me->equip(cure2);
	me->equip(src->createMateria("ice"));

	std::cout << "me use materials\n";
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	me->unequip(1);
	you->equip(cure0);
	me->use(1, *bob);

	std::cout << "\nyou use material\n";
	you->use(0, *bob);

	me->unequip(2);
	you->equip(src->createMateria("ice"));
	you->equip(src->createMateria("cure"));
	you->equip(src->createMateria("ice"));
	you->equip(cure1);
	me->equip(cure1);

	std::cout << "\nme use material\n";
	me->use(1, *bob);

	delete bob;
	delete you;
	delete me;
	delete src;

	return (0);
}
