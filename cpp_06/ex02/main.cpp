#include "Base.hpp"
#include "identify.hpp"
#include <iostream>

int main()
{
    Base *obj = NULL;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "===== TEST " << i + 1 << " =====" << std::endl;

        obj = generate();

        std::cout << "Identify with pointer: ";
        identify(obj);

        std::cout << "Identify with reference: ";
        identify(*obj);

        delete obj;
        obj = NULL;

        std::cout << std::endl;
    }

	std::cout << "===== TEST BASE =====" << std::endl;

	Base *base = new Base();

	std::cout << "Identify with pointer: ";
	identify(base);

	std::cout << "Identify with reference: ";
	identify(*base);

	delete base;

	std::cout << std::endl;
	std::cout << "===== TEST NULL =====" << std::endl;

	Base *nullPtr = NULL;

	std::cout << "Identify with pointer: ";
	identify(nullPtr);

	std::cout << std::endl;
    return 0;
}
