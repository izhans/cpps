#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Use: ./btc <input_file>" << std::endl;
		return 1;
	}
	
	if (BitcoinExchange::initDB())
		BitcoinExchange::process(argv[1]);

	return 0;
}
