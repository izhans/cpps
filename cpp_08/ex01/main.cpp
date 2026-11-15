#include "Span.hpp"
#include <vector>
#include <iostream>

int main()
{
	Span span(10);

	span.addNumber(5);
	span.addNumber(2);
	span.addNumber(1);
	span.addNumber(2);
	span.addNumber(42);
	span.addNumber(4);
	span.addNumber(-42);

	span.print();

	std::cout << span.longestSpan() << std::endl;
	
	return 0;
}
