#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_templates[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const &other);

		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
};

#endif
