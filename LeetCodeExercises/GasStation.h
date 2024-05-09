#pragma once

#include "Core.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();

        int start = 0;
        int tank = 0;

        int i = 0;
        int j = 0;
        while (true)
        {
            if (tank < 0)
            {
                if (i >= n)
                    return -1;

                start = i;
                tank = 0;
            }

            tank += gas[j];
            tank -= cost[j];

            i++;

            j = i % n;

            if (j == start && tank >= 0)
                return start;
        }

    }
};

void test() {
    Solution solution;

    vector<int> gas0 =  { 1, 2, 3, 4, 5 };
    vector<int> cost0 = { 3, 4, 5, 1, 2 };
	solution.canCompleteCircuit(gas0, cost0);

    vector<int> gas1 =  { 2,3,4 };
    vector<int> cost1 = { 3,4,3 };
	solution.canCompleteCircuit(gas1, cost1);
}