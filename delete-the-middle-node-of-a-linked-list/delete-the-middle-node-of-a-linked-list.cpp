#include <bits/stdc++.h>

using namespace std;

//   Definition for singly-linked list.
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
    ListNode *slow_pointer;
    ListNode *fast_pointer;

    ListNode *deleteMiddle(ListNode *head)
    {
    }

    void deleteNode(ListNode *prev_node)
    {
    }
};

int main()
{
    auto ll = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(7, new ListNode(1, new ListNode(2, new ListNode(6)))))));
    auto sol = Solution();
    sol.deleteMiddle(ll);

    auto iterate_node = ll;

    cout << "[";
    while (iterate_node != nullptr)
    {
        cout << iterate_node->val;
        iterate_node = iterate_node->next;
    }
    cout << "]";

    return 0;
}