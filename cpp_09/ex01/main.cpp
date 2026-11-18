#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Use: ./RPN \"<expression>\"" << std::endl;
		return 1;
	}

	RPN rpn;
	rpn.process(argv[1]);
	
	return 0;
}
