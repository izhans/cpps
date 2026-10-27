#include "Array.hpp"
#include <iostream>
#include <string>
#include <exception>

int main()
{
    std::cout << "=== Test 1: Default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;

    std::cout << "\n=== Test 2: Constructor with size ===" << std::endl;
    Array<int> numbers(5);
    std::cout << "Size: " << numbers.size() << std::endl;

    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = (i + 1) * 10;

    std::cout << "Elements: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Test 3: Copy constructor ===" << std::endl;
    Array<int> copy(numbers);

    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;

    copy[0] = 999;
    std::cout << "After modifying copy:" << std::endl;
    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;

    std::cout << "\n=== Test 4: Assignment operator ===" << std::endl;
    Array<int> assigned;
    assigned = numbers;

    std::cout << "Assigned size: " << assigned.size() << std::endl;
    std::cout << "Assigned[1]: " << assigned[1] << std::endl;

    assigned[1] = 777;
    std::cout << "Original[1]: " << numbers[1] << std::endl;
    std::cout << "Assigned[1]: " << assigned[1] << std::endl;

    std::cout << "\n=== Test 5: Out-of-bounds access ===" << std::endl;
    try
    {
        std::cout << numbers[5] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Empty array access ===" << std::endl;
    try
    {
        std::cout << empty[0] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Different type ===" << std::endl;
    Array<std::string> words(2);
    words[0] = "Hola";
    words[1] = "42";
    std::cout << words[0] << " " << words[1] << std::endl;

    std::cout << "\n=== Test 8: Self-assignment ===" << std::endl;
    Array<int> &ref = numbers;
	numbers = ref;

	std::cout << "Size after self-assignment: " << numbers.size() << std::endl;
	std::cout << "numbers[0]: " << numbers[0] << std::endl;

    return 0;
}
