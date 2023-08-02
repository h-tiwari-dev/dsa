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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ll = new ListNode(0);
        ListNode *returnNode = ll;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val >= list2->val)
            {
                ll->next = new ListNode(list2->val);
                list2 = list2->next;
                ll = ll->next;
            }
            else if (list1->val <= list2->val)
            {
                ll->next = new ListNode(list1->val);
                list1 = list1->next;
                ll = ll->next;
            }
        }

        while (list1 != nullptr)
        {
            ll->next = new ListNode(list1->val);
            ll = ll->next;
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            ll->next = new ListNode(list2->val);
            ll = ll->next;
            list2 = list2->next;
        }

        return returnNode->next;
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
    vector<int> test = {-9, 3};
    vector<int> test_1 = {5, 7};
    auto ll = VecToLL(test);
    auto ll_1 = VecToLL(test_1);
    auto r_ll = sol->mergeTwoLists(ll, ll_1);

    while (r_ll != nullptr)
    {
        cout << r_ll->val << " ,";
        r_ll = r_ll->next;
    }
    return 0;
}