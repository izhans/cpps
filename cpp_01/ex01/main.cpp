#include "Zombie.hpp"

int main()
{
	int N = 10;

	std::cout << "Horde incoming" << std::endl;
	Zombie *horde = zombieHorde(N, "Pepe");
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	std::cout << "Horde has passed" << std::endl;
	delete[] horde;
}
