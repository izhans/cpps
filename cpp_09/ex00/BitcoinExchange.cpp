#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	initializeDB(); // ! can throw error
}

BitcoinExchange::~BitcoinExchange() {}
