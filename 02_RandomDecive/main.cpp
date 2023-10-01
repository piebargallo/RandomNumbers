#include <iostream>
#include <random>

int main()
{
	std::random_device rnd;
	std::cout << "Entropy: " << rnd.entropy() << std::endl;
	
	return 0;
}