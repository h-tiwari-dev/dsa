#include <bits/stdc++.h>

using namespace std;

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head;
        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->val == temp->next->val)
            {
                if (temp->next->next != nullptr)
                {
                    auto tempNext = temp->next;
                    temp->next = temp->next->next;
                    delete tempNext;
                    continue;
                }
                else
                {
                    temp->next = nullptr;
                }
            }
            temp = temp->next;
        }
        return head;
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
    auto ll = VecToLL({1, 1, 2, 3, 3});
    auto result = sol->deleteDuplicates(ll);

    while (result != nullptr)
    {
        cout << result->val;
        result = result->next;
    }

    return 0;
}
