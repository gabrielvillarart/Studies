#pragma once
#include "../../LeetCodeExercises/Core.h"

class Solution {
public:
    int scoreOfString(const string& s) {

		const char* c0 = s.c_str();
		const char* c1 = s.c_str() + 1;
		const char* end = c0 + s.length();
		int sum = 0;

		while (true)  {

			sum += *c0 < *c1 ? *c1 - *c0 : *c0 - *c1;
			c0 += 2;
			if (c0 >= end)
				break;

			sum += *c0 < *c1 ? *c1 - *c0 : *c0 - *c1;
			c1 += 2;
			if (c1 >= end)
				break;
		}

		return sum;
    }
};

void test()
{
	string s = "";
	Solution solution;
	solution.scoreOfString("hello");
	solution.scoreOfString("zaz");
}
