#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(6);
	v.push_back(9);
	v.push_back(1);

	std::cout << *easyfind(v, 3) << std::endl;

	try
	{
		std::cout << *easyfind(v, 0) << std::endl;		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
