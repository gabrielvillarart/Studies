#pragma once
#include "Core.h"

class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
            
        unsigned char numsSize = nums.size();
        unsigned char totalMatches = 0;
        unsigned char parsedNums[100] = {};

        unsigned char i = 0;
        while (i < numsSize) {
            if (nums[i] != val) {
                parsedNums[totalMatches] = i;
                totalMatches++;
            }

            i++;
        }
        i = 0;
        while (i < totalMatches) {
            nums[i] = nums[parsedNums[i]];
            i++;
        }
        return totalMatches;
    }
};

void test() {

    vector<int> nums = { 0,4,4,0,4,4,4,0,2 };
    Solution::removeElement(nums, 4);

}