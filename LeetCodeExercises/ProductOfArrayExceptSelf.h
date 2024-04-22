#pragma once
#include "Core.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t length = nums.size();
        size_t last_index = length - 1;

        vector<int> answer(length);
        
        unsigned int prefix = nums[0];
        for (size_t i = 1; i < last_index; i++)
        {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        answer[last_index] = prefix;

        unsigned int suffix = nums[last_index];
        for (size_t i = last_index - 1; i > 0; i--)
        {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        answer[0] = suffix;

        return answer;
    }
};

void test() {
    vector<int> nums0 = {1,2,3,4};
    vector<int> nums1 = {-1,1,0,-3,3};
    Solution solution;
    auto result0 = solution.productExceptSelf(nums0);
    auto result1 = solution.productExceptSelf(nums1);
}

/*
[1,2,3,4]
[0] = ([1] * [2] * [3])

[1] = ([0]) * ([2] * [3])
[2] = ([0] * [1]) * ([3])

[3] = ([0] * [1] * [2])
*/