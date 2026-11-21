#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Use: ./RPN \"<expression>\"" << std::endl;
		return 1;
	}

	try
	{
		RPN::process(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}
