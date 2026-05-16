#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		delete _templates[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;

	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _templates[i];

			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = NULL;
		}
	}

	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = m->clone();

			std::cout << "MateriaSource learned " << m->getType() << std::endl;

			return;
		}
	}

		std::cout << "MateriaSource is full and couldn't learn " << m->getType() << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i]
			&& _templates[i]->getType() == type)
		{
			std::cout << "MateriaSource created " << type << std::endl;

			return (_templates[i]->clone());
		}
	}

	std::cout << type << " doesn't exist in MateriaSource" << std::endl;

	return (0);
}
