#include "Tools/Random.h"
#include "LeetCodeExercises/Core.h"

int main() {
	vector<double> vec = { Random::zeroToOne()};
	while (true) {
		int i = 0;
		while (i < 10) {
			vec.push_back(Random::zeroToOne());
			i++;
		}
		vec.clear();
	}
}