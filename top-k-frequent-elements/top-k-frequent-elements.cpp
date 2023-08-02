#include <bits/stdc++.h>
#include <bitset>

using namespace std;

struct Element
{
    int priority;
    int data;

    Element(int priority, int data) : priority(priority), data(data) {}

    bool operator<(const Element &other) const
    {
        return priority < other.priority;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<Element> pq;
        map<int, int> elementCount;

        for (auto const &num : nums)
        {
            elementCount[num]++;
        }

        for (auto const &pair : elementCount)
        {
            Element elem(pair.second, pair.first);
            pq.push(elem);
        }

        int i = 0;
        vector<int> result;
        while (i < k)
        {
            result.push_back(pq.top().data);
            pq.pop();
            i++;
        }
        return result;
    }
};

int main()
{
    auto sol = Solution();
    vector<int> test = {1, 1, 1, 2, 2, 3};
    auto inorder_result = sol.topKFrequent(test, 2);

    for (auto in_res : inorder_result)
    {
        cout << in_res << " ,";
    }

    return 0;
}