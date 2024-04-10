#include "Core.h"

class Solution {
public:
    int hIndex(const vector<int>& inCitations) {
        auto citations = inCitations;
        sort(citations.begin(), citations.end());

        int i = 0;
        auto it = citations.end();
        while(it != citations.begin())
        {
            it--;
            const int& value = *it;

            if(value <= i)
                break;

            i++;
        }

        return i;
    }
};

void test() {
    Solution solution;
    solution.hIndex({1,3,1});
    solution.hIndex({4,4,0,0});
    solution.hIndex({3,0,6,1,5});
}