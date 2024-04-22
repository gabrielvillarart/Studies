#pragma once
#include "Core.h"

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {

        int numsSize = nums.size();
        int i = 1;
        int j = 0;

        while (i < numsSize) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
            i++;
        }

        return j + 1;
    }
};

void test() {
    vector<int> nums = {1, 1, 2};
	Solution::removeDuplicates(nums);
}