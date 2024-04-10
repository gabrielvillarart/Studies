#include "Core.h"

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        map.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++) 
        {
            auto expected = target - nums[i];

            if ( map.contains(expected) ) 
                return { map[expected], i };

            map[nums[i]] = i;
        }
        return {};
    }
};

template<typename T>
std::string VectorToString(const std::vector<T>& vec)
{
    std::string s;
    for (auto& element : vec)
    {
        s += std::to_string(element);
    }
    return s;
}

void testCase(vector<int>&& nums, int target)
{
    // vector<int> nums = nums;
    auto result = Solution::twoSum(nums, target);
    
    std::string numsString;
    for(int num : nums)
    {
        if (!numsString.empty())
            numsString += ", ";
        
        numsString += std::to_string(num);
    }

    std::cout << "Nums: [ "<< numsString << " ]"
    << "\nTarget: " << std::to_string(target)
    << "\nResult: [ " << (result.empty() ? -1 : result[0])
              << ", " << (result.empty() ? -1 : result[1]) << " ]" << std::endl;

    std::cin.get();
}

void test()
{
    testCase({ 11, 15, 2, 7 }, 9);
    testCase({ 3, 2, 4 }, 6);
    testCase({ 3, 3 }, 6);

    return 0;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

