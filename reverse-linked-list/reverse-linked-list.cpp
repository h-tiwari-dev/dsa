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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *new_ll = new ListNode(0);
        auto ll_to_vec = LLToVec(head);
        reverse(ll_to_vec.begin(), ll_to_vec.end());
        auto temp_ll = new_ll;

        for (auto val : ll_to_vec)
        {
            temp_ll->next = new ListNode(val);
            temp_ll = temp_ll->next;
        }
        // ListNode *tempHead = new ListNode(0, head);
        // recursive_reverseList(tempHead, new_ll);
        return new_ll->next;
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
    // Recursive approch
    int recursive_reverseList(ListNode *head, ListNode *new_ll)
    {
        if (head->next == nullptr)
        {
            return head->val;
        }
        else
        {
            auto tempValue = recursive_reverseList(head->next, new_ll);
            while (new_ll->next != nullptr)
            {
                new_ll = new_ll->next;
            }
            new_ll->next = new ListNode(tempValue);

            return head->val;
        }
    }
};

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
int main()
{
    auto sol = new Solution();
    vector<int> test = {1, 2, 3, 4, 5};
    auto ll = VecToLL(test);
    auto r_ll = sol->reverseList(ll);

    while (r_ll != nullptr)
    {
        cout << r_ll->val << " ,";
        r_ll = r_ll->next;
    }
    return 0;
}