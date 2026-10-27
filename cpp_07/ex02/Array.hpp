#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
	private:
		T *_data;
		unsigned int _size;
	public:
		Array(); // empty array
		Array(unsigned int n); // n elements initalized by default
		~Array();
		Array(const Array<T> &other);
		Array<T> &operator=(const Array<T> &other);

		T &operator[](unsigned int i);
		const T &operator[](unsigned int i) const;

		unsigned int size() const;
};

#include "Array.tpp" // so including this file has the template implementations

#endif
