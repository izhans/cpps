#include "Character.hpp"

Character::Character(): _name("unknown")
{
	std::cout << "Character default constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const &name): _name(name)
{
	std::cout << "Character " << _name << " constructor" << std::endl;

	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const &other): _name(other._name)
{
	std::cout << "Character copy constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

Character &Character::operator=(Character const &other)
{
	std::cout << "Character assignment operator called" << std::endl;

	if (this != &other)
	{
		_name = other._name;

		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}

	return (*this);
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;

			std::cout << _name << " has equipped " << m->getType() << std::endl;

			return;
		}
	}
	std::cout << _name << " couldn't equip " << m->getType() << " because its inventory was full :(" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
		
	if (!_inventory[idx])
		std::cout << _name << " cannot unequip an empty slot :/" << std::endl;
	else
	{
		std::cout << "Unequipped " << _inventory[idx]->getType() << std::endl;
		_inventory[idx] = NULL;
	}	
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return;

	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << _name << " cannot use an inexistent materia :0" << std::endl;
}
