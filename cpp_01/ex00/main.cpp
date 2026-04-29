#include "Zombie.hpp"

int main()
{
	std::cout << "newZombie Alfred" << std::endl;
	Zombie *z = newZombie("Alfred");
	z->announce();
	std::cout << std::endl;

	std::cout << "randomChump Lauren" << std::endl;
	randomChump("Lauren");
	std::cout << std::endl;

	delete z;
}
