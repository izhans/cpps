#include "Span.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <exception>

static void printSeparator(const std::string &title)
{
    std::cout << std::endl;
    std::cout << "========== " << title << " ==========" << std::endl;
}

int main()
{
    // ------------------------------------------------------------
    // Basic scenario
    // ------------------------------------------------------------
    printSeparator("Basic scenario");
	{
		Span sp(5);
	
		std::cout << "Span created with N = 5" << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(7);
		sp.addNumber(-42);
	
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	}	
    
    // ------------------------------------------------------------
    // addNumber exceeding capacity
    // ------------------------------------------------------------
    printSeparator("addNumber exceeding capacity");
	{
		Span sp(3);
	
		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);
	
		std::cout << "Added 3 numbers successfully." << std::endl;
	
		try
		{
			sp.addNumber(40);
			std::cout << "ERROR: should have thrown!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Expected exception: " << e.what() << std::endl;
		}
	}

    // ------------------------------------------------------------
    // addNumbers with array
    // ------------------------------------------------------------
    printSeparator("addNumbers with array");

    {
        Span sp(10);

        int numbers[] = {1, 2, 3, 4, 50};

        sp.addNumbers(numbers, numbers + 5);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }

    // ------------------------------------------------------------
    // addNumbers with list
    // ------------------------------------------------------------
    printSeparator("addNumbers with list");

    {
        std::list<int> numbers;
        numbers.push_back(100);
        numbers.push_back(200);
        numbers.push_back(300);

        Span sp(5);
        sp.addNumbers(numbers.begin(), numbers.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }

    // ------------------------------------------------------------
    // addNumbers exceeding capacity
    // ------------------------------------------------------------
    printSeparator("addNumbers exceeding capacity");

    try
    {
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);
        numbers.push_back(5);

        Span sp(3);
        sp.addNumbers(numbers.begin(), numbers.end());

        std::cout << "ERROR: should have thrown!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    // ------------------------------------------------------------
    // Copy constructor
    // ------------------------------------------------------------
    printSeparator("Copy constructor");

    {
        Span original(5);
        original.addNumber(10);
        original.addNumber(20);
		
        Span copy(original);
        original.addNumber(30);

        std::cout << "Original shortest span: " << original.shortestSpan() << std::endl;
        std::cout << "Copy shortest span: " << copy.shortestSpan() << std::endl;
        std::cout << "Original longest span: " << original.longestSpan() << std::endl;
        std::cout << "Copy longest span: " << copy.longestSpan() << std::endl;
    }

    // ------------------------------------------------------------
    // Assignment operator
    // ------------------------------------------------------------
    printSeparator("Assignment operator");

    {
        Span original(5);
        original.addNumber(1);
        original.addNumber(50);
        original.addNumber(100);

        Span assigned(10);
        assigned.addNumber(999);

        assigned = original;

        std::cout << "Assigned shortest span: "<< assigned.shortestSpan() << std::endl;
        std::cout << "Assigned longest span: " << assigned.longestSpan() << std::endl;
    }

    // ------------------------------------------------------------
    // No sufficient elements for calculting spans
    // ------------------------------------------------------------
    printSeparator("No sufficient elements for calculting spans");

    {
        Span sp(5);
        sp.addNumber(42);

        try
        {
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "ERROR: should have thrown!" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Expected shortestSpan exception: " << e.what() << std::endl;
        }

        try
        {
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
            std::cout << "ERROR: should have thrown!" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Expected longestSpan exception: " << e.what() << std::endl;
        }
    }

    // ------------------------------------------------------------
    // Duplicate values
    // ------------------------------------------------------------
    printSeparator("Duplicate values");

    {
        Span sp(5);

        sp.addNumber(10);
        sp.addNumber(10);
        sp.addNumber(10);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    return 0;
}
