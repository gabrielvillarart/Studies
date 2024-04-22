#pragma once
#include "Core.h"

class Solution {
public:
int jump(vector<int>& nums) {

    int length = nums.size() - 1;

    if(length == 0) 
        return 0;

    int inertia = nums[0];
    int surplus = 0;
    int steps = 1;

    for (int i = 1; i < length; i++) {

        if (inertia > length - i) 
            break;

        const int& impulse = nums[i];

        inertia--;

        int potentialSurplus = impulse - inertia;
        if (potentialSurplus > surplus)
            surplus = potentialSurplus;

        if (inertia == 0) {

            inertia += surplus;
            surplus = 0;
            steps++;
        }
    }

    return steps;
    }

};

void test() {
    vector<int> nums = { 7,0,9,6,9,6,1,7,9,0,1,2,9,0,3 };
    Solution solution;
    int canJump = solution.jump(nums);
}