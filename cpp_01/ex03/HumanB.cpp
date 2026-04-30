#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void HumanB::attack()
{
	if (!_weapon)
		std::cout << _name << " is unarmed" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& value)
{
    _weapon = &value;
}
