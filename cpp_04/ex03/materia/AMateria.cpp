#include "AMateria.hpp"

AMateria::AMateria(): _type("unknown")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other): _type(other._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	std::cout << "AMateria assignment operator called" << std::endl;

	if (this != &other)
		_type = other._type;

	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Using unknown materia with " << target.getName() << std::endl;
}
