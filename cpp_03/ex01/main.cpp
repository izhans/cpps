#include "ScavTrap.hpp"

int main()
{
	std::cout << "===== CONSTRUCTION TEST =====" << std::endl;

	ScavTrap a("Guardian");

	std::cout << std::endl;

	std::cout << "===== ATTACK TEST =====" << std::endl;

	a.attack("enemy");

	std::cout << std::endl;

	std::cout << "===== SPECIAL ABILITY TEST =====" << std::endl;

	a.guardGate();

	std::cout << std::endl;

	std::cout << "===== ENERGY TEST =====" << std::endl;

	for (int i = 0; i < 50; i++)
		a.attack("dummy");

	std::cout << std::endl;

	std::cout << "===== DAMAGE TEST =====" << std::endl;

	ScavTrap b("Crab");

	b.takeDamage(30);
	b.beRepaired(10);
	b.takeDamage(80);

	b.attack("dead target");
	b.beRepaired(10);
	b.takeDamage(20);

	std::cout << std::endl;

	std::cout << "===== COPY TEST =====" << std::endl;

	ScavTrap c(b);
	std::cout << std::endl;

	ScavTrap d;
	std::cout << std::endl;

	d = b;

	std::cout << std::endl;

	return (0);
}
