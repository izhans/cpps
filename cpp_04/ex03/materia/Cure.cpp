#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const &other): AMateria(other)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &other)
{
	std::cout << "Cure assignment operator called" << std::endl;

	(void)other; // subject says: While assigning a Materia to another, copying the type doesn’t make sense.

	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
