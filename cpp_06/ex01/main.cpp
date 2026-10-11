#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;

	data.id = 42;
	data.name = "Bender";
	data.value = 3.14f;

	std::cout << "===== ORIGINAL DATA =====" << std::endl;
	std::cout << "ID: " << data.id << std::endl;
	std::cout << "Name: " << data.name << std::endl;
	std::cout << "Value: " << data.value << std::endl;

	Data *originalPtr = &data;

	std::cout << std::endl;
	std::cout << "===== SERIALIZE =====" << std::endl;
	std::cout << "Original pointer: " << originalPtr << std::endl;

	uintptr_t raw = Serializer::serialize(originalPtr);

	std::cout << "Serialized value: " << raw << std::endl;

	std::cout << std::endl;
	std::cout << "===== DESERIALIZE =====" << std::endl;

	Data *recoveredPtr = Serializer::deserialize(raw);

	std::cout << "Recovered pointer: " << recoveredPtr << std::endl;

	std::cout << std::endl;
	std::cout << "===== COMPARISON =====" << std::endl;

	if (originalPtr == recoveredPtr)
		std::cout << "SUCCESS: pointers are equal." << std::endl;
	else
		std::cout << "ERROR: pointers are different." << std::endl; // change raw

	std::cout << std::endl;
	std::cout << "===== RECOVERED DATA =====" << std::endl;

	std::cout << "ID: " << recoveredPtr->id << std::endl;
	std::cout << "Name: " << recoveredPtr->name << std::endl;
	std::cout << "Value: " << recoveredPtr->value << std::endl;

	return 0;
}
