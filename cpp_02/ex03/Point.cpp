#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {}

Point::Point(float x, float y): _x(x), _y(y) {}

Point::Point(const Point &other): _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		(Fixed) _x = other.getX();
		(Fixed) _y = other.getY();
	}
	
	return (*this);
}

Point::~Point(void) {}

const Fixed Point::getX() const
{
    return _x;
}

const Fixed Point::getY() const
{
    return _y;
}

