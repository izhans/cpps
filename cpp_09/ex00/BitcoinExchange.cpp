#include "BitcoinExchange.hpp"
#include <fstream>
#include <vector>
#include <sstream>

std::ifstream openFile(std::string file);
static bool splitDateAndNum(std::string &line, std::string splitOn, std::string &date, std::string &num);
static bool validDate(std::string date);
static bool validDateFormat(std::string &date);
static bool validateAndCastNumber(std::string rateStr, double &rate);

std::map<std::string, double> BitcoinExchange::_db;

bool BitcoinExchange::initDB()
{
	std::ifstream db_stream = openFile("data.csv");
	if (!db_stream)
		return false;

	std::string line;
	std::getline(db_stream, line); // skip header

	// populate db
	while (getline(db_stream, line))
	{
		std::string date, rateStr;
		double rate;
		
		if (!splitDateAndNum(line, ",", date, rateStr))
			std::cerr << "[SKIPPED] DB Error: missing separator -> " << line << std::endl;
		else if (!validDate(date) || !validateAndCastNumber(rateStr, rate) || rate < 0)
			std::cerr << "[SKIPPED] DB Error: wrong date or rate -> " << line << std::endl;
		else
			_db.insert(std::make_pair(date, rate));
	}
	
	return true;
}

void BitcoinExchange::process(std::string input)
{
	std::ifstream input_stream = openFile(input);
	if (!input_stream)
		return ;

	std::string line;
	std::getline(input_stream, line); // skip header

	while (getline(input_stream, line))
	{
		std::string date, valueStr;
		double value;
		
		if (!splitDateAndNum(line, " | ", date, valueStr) || !validDate(date) || !validateAndCastNumber(valueStr, value))
			std::cerr << "Error: bad input => " << line << std::endl;
		else if (value < 0)
			std::cerr << "Error: not a positive number" << std::endl;
		else if (value > 1000)
			std::cerr << "Error: too large number" << std::endl;
		else
		{
			std::map<std::string, double>::iterator it = _db.upper_bound(date);

			if (it != _db.begin())
			{
				--it;
				double rate = it->second;
				std::cout << date << " => " << value << " = " << value * rate << std::endl;
			}
			else
				std::cerr << "Error: date is too early, bitcoin didn't exist :o" << std::endl;
		}
	}
}

std::ifstream openFile(std::string file)
{
	std::ifstream file_stream;
	file_stream.open(file.c_str());

	if (!file_stream)
		std::cerr << "Cannot open file " << file << std::endl;
	
	return file_stream;
}

static bool splitDateAndNum(std::string &line, std::string splitOn, std::string &date, std::string &num)
{
	size_t sep = line.find(splitOn);

	if (sep == std::string::npos) // sep not found
		return false;

	date = line.substr(0, sep);
	num = line.substr(sep + splitOn.length());
	return true;
}

static bool validDate(std::string date)
{
	if (!validDateFormat(date))
		return false;
	
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	if (year < 1 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	bool leapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

	if (leapYear && month == 2)
		daysInMonth[1] = 29;

	return (day <= daysInMonth[month - 1]);
}

static bool validDateFormat(std::string &date)
{
	if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;

        if (!std::isdigit(date[i]))
            return false;
    }

	return true;
}

static bool validateAndCastNumber(std::string numStr, double &num)
{
	std::stringstream ss(numStr);
	char extra;

	return ((ss >> num) && !(ss >> extra));
}
