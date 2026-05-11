#include "ClapTrap.hpp"

int main()
{
	std::cout << "===== BASIC TEST =====" << std::endl;

	ClapTrap a("Alpha");

	a.attack("enemy");
	a.takeDamage(5);
	a.beRepaired(3);

	std::cout << std::endl;

	std::cout << "===== ENERGY DEPLETION TEST =====" << std::endl;

	ClapTrap b("Beta");

	for (int i = 0; i <= 10; i++)
		b.attack("target");
	
	b.beRepaired(12);

	std::cout << std::endl;

	std::cout << "===== DEATH TEST =====" << std::endl;

	ClapTrap c("Gamma");

	c.takeDamage(5);
	c.takeDamage(10);

	c.attack("someone");
	c.beRepaired(5);
	c.takeDamage(1);

	std::cout << std::endl;

	std::cout << "===== COPY TEST =====" << std::endl;

	ClapTrap d("Delta");
	ClapTrap e(d);

	ClapTrap f;
	f = d;

	std::cout << std::endl;

	return (0);
}
