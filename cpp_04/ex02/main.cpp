#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "========== ABSTRACT CLASS TEST ==========" << std::endl;

	// Animal a; (void) a;
	// ERROR:
	// cannot instantiate abstract class

	// Animal* test = new Animal(); (void) test;
	// ERROR:
	// invalid new-expression of abstract class type 'Animal'

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;

	delete dog;
	delete cat;

	std::cout << std::endl;
	std::cout << "========== END ==========" << std::endl;

	return (0);
}
