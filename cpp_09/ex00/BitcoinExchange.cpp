#include "BitcoinExchange.hpp"
#include <fstream>
#include <vector>

void BitcoinExchange::initDB()
{

	std::ifstream input_stream;
	input_stream.open("data.csv");

	if (!input_stream)
	{
		std::cerr << "Can't open db file" << std::endl;
		return ;
	}

	std::string line;

	while (getline(input_stream, line))
	{
		// TODO store each line in the map
		size_t sep = line.find(",");
		if (sep == std::string::npos) // sep not found
		{
			continue; // TODO print error
		}
		

		std::string date = line.substr(0, sep);
		std::string rate = line.substr(sep +1);

		std::cout << line << " => " << "[" << date << "] [" << rate << "]" << std::endl;

		// ?? TODO validate date & rate?
		// TODO save into map
	}
}


void BitcoinExchange::process(std::string input)
{
	std::ifstream input_stream;
	input_stream.open(input.c_str());

	if (!input_stream)
	{
		std::cerr << "Can't open input file" << std::endl;
		return ;
	}

	std::string line;

	while (getline(input_stream, line))
	{
		size_t sep = line.find(" | ");
		if (sep == std::string::npos) // sep not found
		{
			continue; // TODO print error
		}
		

		std::string date = line.substr(0, sep);
		std::string value = line.substr(sep +3);

		std::cout << line << " => " << "[" << date << "] [" << value << "]" << std::endl;

		// TODO validate date & value
		// print error or search & calculate exchange
	}
}
