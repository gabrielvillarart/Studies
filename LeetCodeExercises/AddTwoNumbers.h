#include "Core.h"

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



template<int size>
class List
{


public:
    List(const int (&arr)[size])
    {
        for (int i = 0; i < size; i++) {

            nodes[i].val = arr[i];

            if (i + 1 < size)
                nodes[i].next = nodes + i + 1;
        }
    }
    List(const string& s)
    {
        for (int i = 0; i < size; i++) {

            nodes[i].val = s[size - i - 1] - 48;

            if (i + 1 < size)
                nodes[i].next = nodes + i + 1;
        }
    }

    ListNode nodes[size];
};


class Solution {
public:

    static ListNode* addTwoNumbers(ListNode* l0, ListNode* l1) {

        ListNode placeholder;
        ListNode* endNode = &placeholder;

        int carry = 0;

        while (true)
        {
            int sum = carry;
            if(l0) sum += l0->val;
            if(l1) sum += l1->val;
            
            if (sum == 0 && (l0 == nullptr) && (l1 == nullptr))
                break;

            endNode->next = new ListNode(sum % 10);
            endNode = endNode->next;

            carry = sum / 10;

            if(l0) l0 = l0->next;
            if(l1) l1 = l1->next;
        }

        return placeholder.next;
    }
};


void test()
{
    List list0({2,4,3});
    List list1({5,6,4});
    Solution::addTwoNumbers(list0.nodes, list1.nodes);
}

constexpr int aa = 5 * 10000;