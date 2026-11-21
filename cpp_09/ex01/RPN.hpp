#include <iostream>

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
