#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>

class BitcoinExchange
{
	private:
		static std::map<std::string, double> _db;
		// OFC
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
	public:
		static bool initDB();
		static void process(std::string input);
};

#endif
