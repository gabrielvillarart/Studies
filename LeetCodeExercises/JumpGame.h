#include "Core.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int innertia = 0;
        int end = nums.size() - 1;

        for (int i = 0; i < end; i++) {

            const int& num = nums[i];

            if (num == 0 && innertia == 0)
                return false;

            if(num > innertia)
                innertia = num;

            innertia--;
        }

        return true;
    }
};

void test() {
    vector<int> nums = {0, 1};
    Solution solution;
    bool canJump = solution.canJump(nums);
}