#ifndef FIXEDPOINT_HPP
#define FIXEDPOINT_HPP

class Fixed
{
	private :
		int value;
		static const int fractionalBits = 8;
	public :
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator = (const Fixed &other);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
