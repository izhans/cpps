#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
	ClapTrap("unknown_clap_name"),
	FragTrap(), ScavTrap(),
	_name("unknown")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;

	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"),
	FragTrap(), ScavTrap(),
	_name(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;

	std::cout << "DiamondTrap " << _name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): 
	ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	_name = other._name;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}

	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << " & ClapTrap name: " << ClapTrap::_name << std::endl;
}
