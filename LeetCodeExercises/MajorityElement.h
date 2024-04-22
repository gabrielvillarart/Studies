#pragma once
#include "Core.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int frequency = 0;

        for (auto num : nums)
        {
            if (frequency == 0) {
                element = num;
                frequency = 1;
                continue;
            }
            
            if (num == element)
                frequency++;
            else
                frequency--;
        }

        return element;
    }

};

void test() {
    vector<int> nums = {2,2,1,1,1,2,2,1,2};
    Solution solution;
    solution.majorityElement(nums);
}