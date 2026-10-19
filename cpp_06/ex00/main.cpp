#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
	{
		std::cout << "Please, pass an arg with a literal to convert" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
	
    return 0;
}
