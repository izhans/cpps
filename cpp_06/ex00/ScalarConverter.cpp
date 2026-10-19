#include "ScalarConverter.hpp"
#include <limits>
#include <cctype>
#include <cstdlib>
#include <cmath>

static bool isSpecial(const std::string &literal);
static double getSpecialValue(const std::string &literal);

static bool isChar(const std::string &literal);
static bool isInt(const std::string &literal);
static bool isFloat(const std::string &literal);
static bool isDouble(const std::string &literal);
static bool isDecimal(const std::string &literal, bool isDouble);

static void printConversions(double value);
static bool isNanOrInf(double value);
static void printDecimal(double value);

/**
 * Checks char 1st because the example submits 0 and is char non displayable
 */
void ScalarConverter::convert(const std::string &literal)
{
    std::cout << literal << std::endl;

	if (literal.empty())
		return;

	double value;

	if (isSpecial(literal))
        value = getSpecialValue(literal);
	else if (isChar(literal))
        value = literal[0];
    else if (isInt(literal))
        value = std::atoi(literal.c_str());
    else if (isFloat(literal) || isDouble(literal))
		value = std::strtod(literal.c_str(), NULL);
    else
    {
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
    }
	
	printConversions(value);
}

static bool isSpecial(const std::string &literal)
{
    return (literal == "nan" || literal == "nanf"
        || literal == "+inf" || literal == "-inf"
        || literal == "+inff" || literal == "-inff"
        || literal == "inf" || literal == "inff");
}

static double getSpecialValue(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf")
        return std::numeric_limits<double>::quiet_NaN();
    if (literal == "-inf" || literal == "-inff")
        return -std::numeric_limits<double>::infinity();
    return std::numeric_limits<double>::infinity();
}


static bool isChar(const std::string &literal)
{
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

static bool isInt(const std::string &literal)
{
    int i = 0;

    if (literal[i] == '+' || literal[i] == '-')
	{
        i++;

		if (!literal[i]) // checks there is digit after sign
			return false;
	}

    while (literal[i])
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }

	double value = std::strtod(literal.c_str(), NULL);

	return value >= std::numeric_limits<int>::min()
    	&& value <= std::numeric_limits<int>::max()
		&& errno != ERANGE;
}

static bool isFloat(const std::string &literal)
{
	if (literal[literal.length() - 1] != 'f')
		return false;
	
	std::string number = literal.substr(0, literal.length() - 1);
	double value = std::strtod(number.c_str(), NULL);

    return isDecimal(number, false)
		&& value >= -std::numeric_limits<float>::min()
    	&& value <= std::numeric_limits<float>::max()
		&& errno != ERANGE;
}

static bool isDouble(const std::string &literal)
{
	std::strtod(literal.c_str(), NULL);

    return isDecimal(literal, true) && errno != ERANGE;
}

/**
 * float numbers CAN have digits only in one side of the dot:
 * 	for example: .02, 2. and 4.2 are valid
 * doubles also accept no decimal value (2)
 */
static bool isDecimal(const std::string &literal, bool isDouble)
{
    size_t i = 0;
    bool hasDigit = false;
    bool hasDot = false;

    if (literal[i] == '+' || literal[i] == '-')
        i++;

    while (i < literal.length())
    {
        if (std::isdigit(literal[i]))
            hasDigit = true;
        else if (literal[i] == '.' && !hasDot)
            hasDot = true;
        else
            return false;
        i++;
    }

    return hasDigit && (hasDot || isDouble);
}

static void printConversions(double value)
{
	std::cout << "char: ";
    if (isNanOrInf(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(value))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    std::cout << "int: ";
    if (isNanOrInf(value)
        || value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    std::cout << "float: ";
	if (!isNanOrInf(value)
		&& (value < -std::numeric_limits<float>::max()
		|| value > std::numeric_limits<float>::max()))
        std::cout << "impossible" << std::endl;
    else
	{
		printDecimal(static_cast<float>(value));
		std::cout << "f" << std::endl;
	}
    
	std::cout << "double: ";
	printDecimal(value);
	std::cout << std::endl;
}

static bool isNanOrInf(double value)
{
    return value != value
		|| value == std::numeric_limits<double>::infinity()
        || value == -std::numeric_limits<double>::infinity();
}

static void printDecimal(double value)
{
    double integerPart;

    std::cout << value;
    if (!isNanOrInf(value) && std::modf(value, &integerPart) == 0.0)
        std::cout << ".0";
}
