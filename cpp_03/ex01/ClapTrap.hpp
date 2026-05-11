#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	protected :
		std::string	_name;
		int			_hitPoints; // represents the health of the claptrap
		int			_energyPoints;
		int			_attackDamage;
	public :
		ClapTrap(void);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap(void);
		
		ClapTrap(std::string name);
		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif
