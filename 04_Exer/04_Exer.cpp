/* Modify your solution to Exercise 23-1. Instead of using a uniform distribution, use
   a negative_binomial_distribution. */

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
	mt19937 engine{ static_cast<mt19937::result_type>(seed) };
	negative_binomial_distribution<int> distribution{ 2, 0.75 };
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
