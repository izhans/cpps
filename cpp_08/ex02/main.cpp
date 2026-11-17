#include "MutantStack.hpp"
#include <iostream>
#include <stack>

static void printSeparator(const std::string &title)
{
    std::cout << std::endl;
    std::cout << "========== " << title << " ==========" << std::endl;
}

int main()
{
    // ------------------------------------------------------------
    // Basic stack operations
    // ------------------------------------------------------------
    printSeparator("Basic stack operations");

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl; // 17

    mstack.pop();

    std::cout << "Top after pop: " << mstack.top() << std::endl; // 5

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Size: " << mstack.size() << std::endl; // 5


    // ------------------------------------------------------------
    // Normal iterator
    // ------------------------------------------------------------
    printSeparator("Normal iterator");

    MutantStack<int>::iterator it;

    std::cout << "Elements: ";

	for (it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " "; // 5 3 5 737 0
    std::cout << std::endl;

    it = mstack.begin();
	*it = 42;

    std::cout << "Elements after modification: ";

    for (it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " "; // 42 3 5 737 0

    std::cout << std::endl;

	// ------------------------------------------------------------
    // Reverse iterator
    // ------------------------------------------------------------
    printSeparator("Reverse iterator");

    MutantStack<int>::reverse_iterator rit;

    std::cout << "Reverse elements: ";

	for (rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " "; // 0 737 5 3 42

    std::cout << std::endl;

    rit = mstack.rbegin();

    if (rit != mstack.rend())
        *rit = 999;

    std::cout << "Reverse elements after modification: ";
	for (rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " "; // 999 737 5 3 42

    std::cout << std::endl;

    // ------------------------------------------------------------
    // 4. Const iterator
    // ------------------------------------------------------------
    printSeparator("Const iterator");

    const MutantStack<int> constStack(mstack);

    MutantStack<int>::const_iterator cit;

    std::cout << "Const elements: ";
    for (cit = mstack.begin(); cit != mstack.end(); ++cit)
        std::cout << *cit << " ";

    std::cout << std::endl;

	// *cit = 100; // doesn't compile
    
    // ------------------------------------------------------------
    // 7. const_reverse_iterator
    // ------------------------------------------------------------
    printSeparator("Const reverse iterator");

    const MutantStack<int> constRevStack(mstack);

    MutantStack<int>::const_reverse_iterator crit;

    std::cout << "Const reverse elements: ";

	for (crit = mstack.rbegin(); crit != mstack.rend(); ++crit)
        std::cout << *crit << " ";

    std::cout << std::endl;
	
	// *crit = 123; // doesn't compile

    // ------------------------------------------------------------
    // Empty stack
    // ------------------------------------------------------------
    printSeparator("Empty stack");

    MutantStack<int> empty;

    std::cout << "Empty: " << (empty.empty() ? "yes" : "no") << std::endl;
    std::cout << "Size: " << empty.size() << std::endl;
    std::cout << "begin() == end(): " << (empty.begin() == empty.end() ? "yes" : "no") << std::endl;
    std::cout << "rbegin() == rend(): " << (empty.rbegin() == empty.rend() ? "yes" : "no") << std::endl;

    return 0;
}
