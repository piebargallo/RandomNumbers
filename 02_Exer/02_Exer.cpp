/* Modify your solution to Exersice 23-1 to use a ranlu48 engine instead of the mersenne twister. */

#include <ctime>
#include <iostream>
#include <random>
#include <functional>
#include <format>

using namespace std;

auto createDiceValueGenerator()
{
	random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	ranlux48 engine{ static_cast<ranlux48::result_type>(seed) };
	uniform_int_distribution<int> distribution{ 1, 6 };
	return bind(distribution, engine);
}

int main()
{
	auto generator{ createDiceValueGenerator() };

	while (true)
	{
		cout << "Throw two dice? (y or n): ";
		char answer;
		cin >> answer;
		if (answer == 'n' || answer == 'N') {
			break;
		}

		auto dieValue1{ generator() };
		auto dieValue2{ generator() };
		cout << format("{} & {}\n", dieValue1, dieValue2);
	}
}
