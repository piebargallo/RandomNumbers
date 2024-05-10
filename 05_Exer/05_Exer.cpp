/* Take the source code from earlier in this chapter used to generate histograms to make graphs of distribution,
   and experiment a bit with different distributions. Try to plot the graps in a spreadsheet application to see the
   effects of a distribution. The code can be foundin the downloable source code archive in the folder 
   c23_code\01_Random. You can take either the 06_uniform_int_distribution.cpp or the 07_normal_distribution.cpp
   file depending on whether your distribution uses integers or doubles. */

#include <ctime>
#include <random>
#include <functional>
#include <map>
#include <fstream>

using namespace std;

int main()
{
	const unsigned int Start{ 1 };
	const unsigned int End{ 99 };
	const unsigned int Iterations{ 1'000'000 };

	random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	mt19937 engine{ static_cast<mt19937::result_type>(seed) };
	exponential_distribution<double> distribution{ 0.5 };
	auto generator{ bind(distribution, engine) };
	map<int, int> histogram;
	for (unsigned int i{ 0 }; i < Iterations; ++i) {
		int randomNumber{ static_cast<int>(generator()) };
		// Search map for a key=randomNumber. If found, add 1 to the value associated
		// with that key. If not found, add the key to the map with value 1.
		++(histogram[randomNumber]);
	}

	// Write to a CSV file.
	ofstream of{ "res.csv" };
	for (unsigned int i{ Start }; i <= End; ++i) {
		of << i << ";" << histogram[i] << endl;
	}
}
