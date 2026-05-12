#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private :
		std::string	_name;
	public :
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap(void);

		DiamondTrap(std::string name);
		void	attack(const std::string &target);
		void	whoAmI();
};

#endif
