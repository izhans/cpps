#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T &value)
{
	std::cout << value << " ";
}

void incrementInt(int &n)
{
    n++;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t len = 5;

    std::cout << "Original array: ";
    iter(numbers, len, print<int>);
    std::cout << std::endl;

    iter(numbers, len, incrementInt);

    std::cout << "After increment: ";
    iter(numbers, len, print<int>);
    std::cout << std::endl;

    const std::string words[] = {"Hola", "mundo", "CPP07"};
	len = 3;

    std::cout << "Strings: ";
    iter(words, len, print<std::string>);
    std::cout << std::endl;

    return 0;
}
