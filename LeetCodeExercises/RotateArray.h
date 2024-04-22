#pragma once
#include "Core.h"

class Solution {
public:
    static inline void swap(int& a, int& b) {

        if (a == b) return;

        int temp = a;
        a = b;
        b = temp;

    }

    static void rotate(vector<int>& nums, int k) {

        int numsSize = nums.size();
        k %= numsSize;

        if (k == 0) return;

        int handPos = k;
        int handStartPos = handPos;
        int holdingValue = nums[0];

        int iteration = 0;
        while (iteration < numsSize) {
            swap(nums[handPos], holdingValue);
            handPos += k;
            handPos %= numsSize;

            if (handPos == handStartPos) {
                handStartPos++;
                handPos++;
                holdingValue = nums[handPos-k];
            }

            iteration++;
        }
    }

};

void test() {
    vector<int> nums = {0,1,2,3,4,5};
	Solution::rotate(nums, 5);
}