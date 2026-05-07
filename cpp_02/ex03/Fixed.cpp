#include "Fixed.hpp"

Fixed::Fixed(void): _value(0) {}

Fixed::Fixed(const int value)
{
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	_value = other.getRawBits();
}

Fixed::~Fixed(void) {}

Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	return (num1._value < num2._value) ? num1 : num2;
}

Fixed &Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return (num1._value < num2._value) ? (Fixed &) num1 : (Fixed &) num2;
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	return (num1._value > num2._value) ? num1 : num2;
}

Fixed &Fixed::max(const Fixed& num1, const Fixed& num2)
{
	return (num1._value > num2._value) ? (Fixed &) num1 : (Fixed &) num2;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
	return (float) _value / (1 << _fractionalBits);
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other.getRawBits();
	
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}

bool Fixed::operator>(const Fixed &toCompare)
{
	return _value > toCompare._value;
}

bool Fixed::operator<(const Fixed &toCompare)
{
	return _value < toCompare._value;
}

bool Fixed::operator>=(const Fixed &toCompare)
{
	return _value >= toCompare._value;
}

bool Fixed::operator<=(const Fixed &toCompare)
{
	return _value <= toCompare._value;
}

bool Fixed::operator==(const Fixed &toCompare)
{
	return _value == toCompare._value;
}

bool Fixed::operator!=(const Fixed &toCompare)
{
	return _value != toCompare._value;
}

Fixed Fixed::operator+(const Fixed &toOperate)
{
	return Fixed(this->toFloat() + toOperate.toFloat());
}

Fixed Fixed::operator-(const Fixed &toOperate)
{
	return Fixed(this->toFloat() - toOperate.toFloat());
}

Fixed Fixed::operator*(const Fixed &toOperate)
{
	return Fixed(this->toFloat() * toOperate.toFloat());
}

Fixed Fixed::operator/(const Fixed &toOperate)
{
	return Fixed(this->toFloat() / toOperate.toFloat());
}

Fixed &Fixed::operator++(void)
{
	++_value;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	--_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed f = *this;
	_value++;
	return f;
}

Fixed Fixed::operator--(int)
{
	Fixed f = *this;
	_value--;
	return f;
}
