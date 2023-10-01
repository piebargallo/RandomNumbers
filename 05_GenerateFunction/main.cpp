#include <ctime>
#include <iostream>
#include <random>
#include <algorithm>
#include <functional>
#include <vector>


// Using C++20 abbreviated function template syntax.
void fillVector(std::vector<int>& values, const auto& generator)
{
	generate(begin(values), end(values), generator);
}

int main()
{
	std::random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	std::mt19937 engine{ static_cast<std::mt19937::result_type>(seed) };
	std::uniform_int_distribution<int> distribution{ 1, 99 };

	auto generator{ bind(distribution, engine) };

	std::vector<int> values(10);
	fillVector(values, generator);

	for (auto i : values) {
		std::cout << i << "  ";
	}
	std::cout << std::endl;

	return 0;
}
