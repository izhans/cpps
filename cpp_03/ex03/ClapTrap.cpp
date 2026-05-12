#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("unknown"),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name),
	  _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}

	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack because it has no hit points left" << std::endl;
		return;
	}

	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot attack because it has no energy points left" << std::endl;
		return;
	}

	_energyPoints--;

	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already destroyed" << std::endl;
		return;
	}

	_hitPoints -= amount;

	if (_hitPoints < 0)
		_hitPoints = 0;

	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	std::cout << "Remaining hit points: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair itself because it has no hit points left" << std::endl;
		return;
	}

	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair itself because it has no energy points left" << std::endl;
		return;
	}

	_energyPoints--;
	_hitPoints += amount;

	std::cout << "ClapTrap " << _name << " repairs itself and recovers " << amount << " hit points!" << std::endl;
	std::cout << "Current hit points: " << _hitPoints << std::endl;
}
