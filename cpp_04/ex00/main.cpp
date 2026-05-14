#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "========== BASIC SUBJECT TEST ==========" << std::endl;

	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << meta->getType() << std::endl;

	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	
	delete dog;
	delete cat;
	delete meta;

	std::cout << std::endl;
	std::cout << "========== WRONG ANIMAL TEST ==========" << std::endl;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;

	std::cout << wrong->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;

	std::cout << std::endl;

	wrong->makeSound();
	wrongCat->makeSound(); // will execute parent makeSound() bc its not virtual

	std::cout << std::endl;

	delete wrong;
	delete wrongCat;

	std::cout << std::endl;
	std::cout << "========== ARRAY OF ANIMALS ==========" << std::endl;

	Animal* animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Animal();

	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << std::endl;
	std::cout << "========== COPY TEST ==========" << std::endl;

	Dog originalDog;
	Dog copiedDog(originalDog);
	std::cout << std::endl;

	Cat originalCat;
	Cat assignedCat;
	assignedCat = originalCat;
	std::cout << std::endl;

	copiedDog.makeSound();
	assignedCat.makeSound();

	std::cout << std::endl;
	std::cout << "========== STACK POLYMORPHISM TEST ==========" << std::endl;

	Dog stackDog;
	Cat stackCat;

	Animal* ptr1 = &stackDog;
	Animal* ptr2 = &stackCat;

	ptr1->makeSound();
	ptr2->makeSound();

	std::cout << std::endl;
	std::cout << "========== END OF PROGRAM ==========" << std::endl;

	return (0);
}
