#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s; // is a pointer (same as c)
	std::string &stringREF = s; // is an alias (different name, same memory direction)

	std::cout << "Memory adresses" << std::endl;
	std::cout << "s: " << &s << std::endl;
	std::cout << "stringPTR: " << &stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "Values" << std::endl;
	std::cout << "s: " << s << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
}
