#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "========== SUBJECT TEST ==========" << std::endl;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;

	delete dog;
	delete cat;

	std::cout << std::endl;
	std::cout << "========== DEEP COPY TEST ==========" << std::endl;

	Dog original;

	original.setIdea(0, "I want a bone");
	original.setIdea(1, "I hate cats");

	Dog copy(original);

	std::cout << std::endl;

	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Copy idea: " << copy.getIdea(0) << std::endl;

	std::cout << std::endl;

	original.setIdea(0, "I prefer chicken");

	std::cout << "** After modifying original **" << std::endl;
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Copy idea: " << copy.getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "========== ASSIGNMENT TEST ==========" << std::endl;

	Cat a;
	a.setIdea(0, "sleep");
	std::cout << std::endl;

	Cat b;
	b = a;
	std::cout << std::endl;

	std::cout << "A idea: " << a.getIdea(0) << std::endl;
	std::cout << "B idea: " << b.getIdea(0) << std::endl;
	std::cout << std::endl;

	b.setIdea(0, "destroy humanity");

	std::cout << "** After modifying b (copy) **" << std::endl;
	std::cout << "A idea: " << a.getIdea(0) << std::endl;
	std::cout << "B idea: " << b.getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "========== ARRAY TEST ==========" << std::endl;

	Animal* animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	std::cout << std::endl;

	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	std::cout << std::endl;
	std::cout << "========== DESTROY ARRAY TEST ==========" << std::endl;

	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << std::endl;
	std::cout << "========== END ==========" << std::endl;

	return (0);
}
