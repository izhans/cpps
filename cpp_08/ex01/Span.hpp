#ifndef SPAN_HPP
# define SPAN_HPP

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
		Span(const Span &other);
		Span &operator=(const Span &other);

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		// void print();

		template <typename T_iterator>
		void addNumbers(T_iterator first, T_iterator last)
		{
			for (; first != last; ++first)
				addNumber(*first);
		}
};

#endif
