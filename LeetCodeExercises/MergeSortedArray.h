#include "Core.h"

class Solution {
public:
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        m--;
        int i = n + m;
        n--;

        while (i >= 0)
        {
            if (m < 0) {

                nums1[i] = nums2[n];
                n--;
            }
            else if (n < 0) {

                break;
            }
            else if (nums1[m] > nums2[n]) {

                nums1[i] = nums1[m];
                m--;
            }
            else {

                nums1[i] = nums2[n];
                n--;
            }

            i--;
        }
    }
};

void test()
{
    vector<int> nums1 = { 2,4,6 };
    int nums1_size = nums1.size();
    vector<int> nums2 = { 1,3,5 };
    int nums2_size = nums2.size();
    nums1.resize(nums1_size + nums2_size);

    Solution::merge(nums1, nums1_size, nums2, nums2_size);
}