#include "FragTrap.hpp"

int main()
{
	std::cout << "===== CONSTRUCTION TEST =====" << std::endl;

	FragTrap a("Fraggy");
	std::cout << std::endl;

	std::cout << "===== BASIC TESTS =====" << std::endl;

	a.attack("enemy");
	std::cout << std::endl;
	
	a.takeDamage(40);
	std::cout << std::endl;
	
	a.beRepaired(20);
	std::cout << std::endl;

	std::cout << "===== HIGH FIVE TEST =====" << std::endl;

	a.highFivesGuys();
	std::cout << std::endl;

	std::cout << "===== ENERGY DEPLETION TEST =====" << std::endl;

	for (int i = 0; i < 99; i++)
		a.attack("training dummy");

	std::cout << std::endl;

	std::cout << "===== DEATH TEST =====" << std::endl;

	FragTrap b("Destroyed");
	std::cout << std::endl;

	b.takeDamage(150);
	std::cout << std::endl;

	b.attack("nobody");
	b.beRepaired(10);
	b.highFivesGuys();

	std::cout << std::endl;

	std::cout << "===== COPY TEST =====" << std::endl;

	FragTrap c(a);
	std::cout << std::endl;

	FragTrap d;
	std::cout << std::endl;

	d = a;
	std::cout << std::endl;

	return (0);
}
