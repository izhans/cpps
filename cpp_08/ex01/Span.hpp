#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
#include <set>

class Span
{
	private:
		unsigned int _N;
		std::multiset<int> _numbers;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		// TODO Orthodox Canonical Form

		void addNumber(int n);
		// TODO void addNumbers(???);
		int shortestSpan();
		int longestSpan();

		// void print();
};

Span::Span(): _N(0) {}

Span::Span(unsigned int N): _N(N) {}

Span::~Span(){}

void Span::addNumber(int n)
{
	if (_numbers.size() < _N)
		_numbers.insert(n);
	else
		std::cout << "Max elements of the span reached" << std::endl;
}

// TODO void addNumbers(???);

int Span::shortestSpan()
{
	return 0; // TODO
}

int Span::longestSpan()
{
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

#endif
