#include "RPN.hpp"

static int operate(int a, int b, char op);
static bool hasValidFormat(std::string &expression);
static bool isOperand(char c);

void RPN::process(std::string expression)
{	
	if (!hasValidFormat(expression))
		throw std::runtime_error("invalid format");
	
	std::stack<int> numbers;

	for (size_t i = 0; i < expression.length(); i += 2)
	{
		char c = expression[i];

		if (isdigit(c))
			numbers.push(c - '0');
		else // isOperand
		{
			if (numbers.size() < 2)
				throw std::runtime_error("operand needs 2 digits to operate");

			// pick numbers
			int b = numbers.top();
			numbers.pop();
			int a = numbers.top();
			numbers.pop();

			// operate and save result
			int res = operate(a, b, c);
			numbers.push(res);
		}
	}

	if (numbers.size() != 1)
		throw std::runtime_error("there are still numbers on the stack");
	
	std::cout << numbers.top() << std::endl;
}

static int operate(int a, int b, char op)
{
	int res;

	if (op == '+')
		res = a + b;
	else if (op == '-')
		res = a - b;
	else if (op == '*')
		res = a * b;
	else
	{
		if (b == 0)
			throw std::runtime_error("cannot divide by 0");
		
		res = a / b;
	}

	// std::cout << "operate: " << a << " " << op << " " << b << " = " << res << std::endl;

	return res;
}

/**
 * @brief checks if an expression format is valid
 * chars in even positions (0, 2...) must be digits or operands
 * chars in odd positions (1, 3...) must be spaces
 */
static bool hasValidFormat(std::string &expression)
{
	if (expression.length() % 2 != 1) // lenght has to be odd: "1 2 +" -> len = 5
		return false;
	
	for (size_t i = 0; i < expression.length(); i++)
	{
		if ((i % 2 == 0 && !isdigit(expression[i]) && !isOperand(expression[i])) || (i % 2 == 1 && expression[i] != ' '))
			return false;
	}

	return true;
}

static bool isOperand(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
