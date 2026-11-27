#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>

class RPN
{
	private:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
	public:
		static void process(std::string expression);
};

#endif
