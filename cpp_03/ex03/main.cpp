#include "DiamondTrap.hpp"

int main()
{
	std::cout << "===== CONSTRUCTION TEST =====" << std::endl;

	DiamondTrap a("Diamond");

	std::cout << std::endl;

	std::cout << "===== WHO AM I TEST =====" << std::endl;

	a.whoAmI();

	std::cout << std::endl;

	std::cout << "===== ATTACK TEST =====" << std::endl;

	a.attack("enemy");

	std::cout << std::endl;

	std::cout << "===== SCAVTRAP ABILITY TEST =====" << std::endl;

	a.guardGate();

	std::cout << std::endl;

	std::cout << "===== FRAGTRAP ABILITY TEST =====" << std::endl;

	a.highFivesGuys();

	std::cout << std::endl;

	std::cout << "===== DAMAGE / REPAIR TEST =====" << std::endl;

	a.takeDamage(40);
	a.beRepaired(20);

	std::cout << std::endl;

	std::cout << "===== ENERGY DEPLETION TEST =====" << std::endl;

	for (int i = 0; i < 49; i++)
		a.attack("dummy");

	std::cout << std::endl;

	std::cout << "===== DEATH TEST =====" << std::endl;

	DiamondTrap b("Broken");
	std::cout << std::endl;

	b.takeDamage(200);

	b.attack("nobody");
	b.beRepaired(10);
	b.guardGate();
	b.highFivesGuys();
	b.whoAmI();

	std::cout << std::endl;

	std::cout << "===== COPY CONSTRUCTOR TEST =====" << std::endl;

	DiamondTrap c(a);

	std::cout << std::endl;

	std::cout << "===== ASSIGNMENT OPERATOR TEST =====" << std::endl;

	DiamondTrap d;
	std::cout << std::endl;

	d = a;
	std::cout << std::endl;

	std::cout << "===== END OF PROGRAM =====" << std::endl;

	return (0);
}
