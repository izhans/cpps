#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	value = other.getRawBits();
}

Fixed &Fixed::operator = (const Fixed &other)
{
	std::cout << "= operator called" << std::endl;

	if (this != &other)
		value = other.getRawBits();
	
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called" << std::endl;

	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called" << std::endl;

	this->value = raw;
}
