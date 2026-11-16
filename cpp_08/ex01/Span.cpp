#include "Span.hpp"

Span::Span(): _N(0) {}

Span::Span(unsigned int N): _N(N) {}

Span::~Span(){}

Span::Span(const Span &other): _N(other._N), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int n)
{
	if (_numbers.size() < _N)
		_numbers.insert(n);
	else
		throw std::runtime_error("Max elements of the span reached");
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::runtime_error("No span can be found");
	
	std::set<int>::iterator first = _numbers.begin();
	std::set<int>::iterator second = ++_numbers.begin();
	
	long span = *second - *first;

	for (; second != _numbers.end(); ++first, ++second)
	{
		if (*second - *first < span)
		{
			span = *second - *first;
			if (span == 0)
				break;
		}
	}
	
	return span;
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::runtime_error("No span can be found");
	
	std::set<int>::iterator first = _numbers.begin();
	std::set<int>::iterator last = _numbers.end();
	
	return *(--last) - *first;
}

/*
void Span::print()
{
	std::cout << "All elements of the span: ";
	for(std::set<int>::iterator it = _numbers.begin(); it != _numbers.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
*/
