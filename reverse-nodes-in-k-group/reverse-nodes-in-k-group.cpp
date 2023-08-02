#include <bits/stdc++.h>
#include <bitset>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        auto ll_list = LLToVec(head);
        vector<int> new_list = {};

        int i = k;
        while (i <= ll_list.size())
        {
            for (int j = i - 1; j >= i - k; j--)
            {
                new_list.push_back(ll_list[j]);
            }
            i = i + k;
        }
        for (int j = i - k; j < ll_list.size(); j++)
        {
            new_list.push_back(ll_list[j]);
        }

        return VecToLL(new_list);
    }
    vector<int> LLToVec(ListNode *head)
    {
        vector<int> new_vector = {};
        while (head != nullptr)
        {
            new_vector.push_back(head->val);
            head = head->next;
        }
        return new_vector;
    }
    ListNode *VecToLL(vector<int> list)
    {
        ListNode *start_head = new ListNode(0);
        ListNode *head = start_head;

        for (int item : list)
        {
            head->next = new ListNode(item);
            head = head->next;
        }
        return start_head->next;
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test = {1, 2, 3, 4, 5};
    auto ll = sol->VecToLL(test);
    auto r_ll = sol->reverseKGroup(ll, 3);

    while (r_ll != nullptr)
    {
        cout << r_ll->val << " ,";
        r_ll = r_ll->next;
    }
    return 0;
}