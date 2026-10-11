#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

/**
 * dynamic_cast tries to converts one object to an specific class,
 * 	if it fails (object wasn't from that class):
 *  - returns NULL if arg was a pointer
 *  - throws bad_cast if arg was a reference
 */

Base *generate(void)
{
	int random = std::rand() % 3;

	if (random == 0)
	{
		std::cout << "Generated A" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "Generated B" << std::endl;
		return new B();
	}
	std::cout << "Generated C" << std::endl;
	return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Object couldn't be dynamic casted" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) {}

	std::cout << "Object couldn't be dynamic casted" << std::endl;
}
