#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "../materia/AMateria.hpp"

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4]; // https://stackoverflow.com/a/33123456
	public:
		Character();
		Character(std::string const &name);
		Character(Character const &other);
		~Character();
		Character &operator=(Character const &other);

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif
