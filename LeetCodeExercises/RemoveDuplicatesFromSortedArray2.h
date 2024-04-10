#include "Core.h"

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {

        int numsSize = nums.size();

        if (numsSize <= 2) return numsSize;

        int j = 1;
        int i = 2;

        while (i < numsSize) {

            if (nums[j - 1] != nums[i]) {

                nums[++j] = nums[i];
            }

            i++;
        }
        
        return ++j;
    }
};

void test() {
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
	Solution::removeDuplicates(nums);
}