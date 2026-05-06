#ifndef FIXEDPOINT_HPP
#define FIXEDPOINT_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	private :
		int _value;
		static const int _fractionalBits = 8;
	public :
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		Fixed &operator = (const Fixed &other);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
	};

std::ostream &operator << (std::ostream& os, const Fixed& f);

#endif
