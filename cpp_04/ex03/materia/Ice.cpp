#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const &other): AMateria(other)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &other)
{
	std::cout << "Ice assignment operator called" << std::endl;

	(void)other; // subject says: While assigning a Materia to another, copying the type doesn’t make sense.

	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
