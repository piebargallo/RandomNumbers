/* Write a loop asking the user if dice should be throw or not. If yes, throw a die twicw using a uniform distribution
   and print the two numbers to the console. If no, stop the program. Use the standard mt19937 Mersenne twister
   engine. */
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

