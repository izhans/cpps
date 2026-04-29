#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(void)
{
	std::cout << "DEP " << _name << std::endl;

}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}
