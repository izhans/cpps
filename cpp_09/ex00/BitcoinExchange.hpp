#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _db;
		// OFC
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
	public:
		static void initDB();
		static void process(std::string input);
};
