#include <iostream>

#include "materia/Ice.hpp"
#include "materia/Cure.hpp"
#include "materia/AMateria.hpp"
#include "materiaSource/MateriaSource.hpp"
#include "character/Character.hpp"

int main()
{
	std::cout << "========== MATERIA SOURCE TEST ==========" << std::endl;

	IMateriaSource* src = new MateriaSource();

	AMateria* learned_ice = new Ice();
	AMateria* learned_cure = new Cure();

	src->learnMateria(learned_ice);
	src->learnMateria(learned_cure);

	delete learned_ice;
	delete learned_cure;

	std::cout << std::endl;

	AMateria* tmp = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("cure");
	AMateria* tmp3 = src->createMateria("fire"); // will fail -> NULL

	std::cout << std::endl;

	delete tmp;
	delete tmp2;
	delete tmp3; // NULL

	std::cout << std::endl;

	std::cout << "========== CHARACTER TEST ==========" << std::endl;

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	std::cout << std::endl;

	me->equip(ice);
	me->equip(cure);
	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	me->unequip(0);
	me->use(0, *bob); // nothing should happen

	std::cout << std::endl;

	delete ice;  // we have to delete bc unequip doesnt delete
	// we dont delete cure because now its the character responsability

	std::cout << std::endl;

	std::cout << "========== COPY TEST ==========" << std::endl;

	Character original("original");
	original.equip(src->createMateria("ice"));

	Character copy = original; // deep copy

	original.use(0, *bob);
	copy.use(0, *bob);

	std::cout << std::endl;

	std::cout << "========== ASSIGNMENT TEST ==========" << std::endl;

	Character a("A");
	Character b("B");

	a.equip(src->createMateria("cure"));
	b = a;

	a.use(0, *bob);
	b.use(0, *bob);

	std::cout << std::endl;

	std::cout << "========== CLEANUP ==========" << std::endl;

	delete me;
	delete bob;
	delete src;

	std::cout << "========== END ==========" << std::endl;

	return 0;
}