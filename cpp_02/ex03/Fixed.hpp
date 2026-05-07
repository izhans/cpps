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
		~Fixed(void);

		static Fixed& min(Fixed& num1, Fixed& num2);
		static Fixed& min(const Fixed& num1, const Fixed& num2);
		static Fixed& max(Fixed& num1, Fixed& num2);
		static Fixed& max(const Fixed& num1, const Fixed& num2);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		Fixed &operator=(const Fixed &other);

		// comparison
		bool operator>(const Fixed& toCompare);
		bool operator<(const Fixed& toCompare);
		bool operator>=(const Fixed& toCompare);
		bool operator<=(const Fixed& toCompare);
		bool operator==(const Fixed& toCompare);
		bool operator!=(const Fixed& toCompare);

		// arithmetic
		Fixed operator+(const Fixed& toOperate);
		Fixed operator-(const Fixed& toOperate);
		Fixed operator*(const Fixed& toOperate);
		Fixed operator/(const Fixed& toOperate);

		// pre inc/dec
		Fixed& operator++(void);
		Fixed& operator--(void);
		// post inc/dec
		Fixed operator++(int);
		Fixed operator--(int);
	};

std::ostream &operator << (std::ostream& os, const Fixed& f);

#endif
