#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, const size_t len, void (*func)(T &))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>
void iter(const T *arr, const size_t len, void (*func)(const T &))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif
