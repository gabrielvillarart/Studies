#include "Core.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            const int& price = prices[i];

            if (price < lowestPrice) {
                lowestPrice = price;
                continue;
            }

            int profit = price - lowestPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};

void test() {
    vector<int> nums = {7,1,5,3,6,4};
    Solution solution;
    solution.maxProfit(nums);
}