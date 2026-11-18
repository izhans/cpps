#include <map>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _db;
		void initializeDB();
	public:
		BitcoinExchange();
		~BitcoinExchange();
		// TODO OCF
};
