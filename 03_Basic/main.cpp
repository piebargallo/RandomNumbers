#include <ctime>
#include <iostream>
#include <random>

int main()
{
	std::random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	std::mt19937 engine{ static_cast<std::mt19937::result_type>(seed) };

	std::uniform_int_distribution<int> distribution{ 1, 99 };
	std::cout << distribution(engine) << std::endl;

	return 0;
}
