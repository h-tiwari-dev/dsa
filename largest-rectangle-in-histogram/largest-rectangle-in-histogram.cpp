#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        stack<pair<int, int>> mono_inc_stack = {};

        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;
            while (!mono_inc_stack.empty() && mono_inc_stack.top().second > heights[i])
            {
                pair<int, int> top = mono_inc_stack.top();
                mono_inc_stack.pop();
                maxArea = max(maxArea, top.second * (i - top.first));
                start = top.first;
            }
            mono_inc_stack.push({start, heights[i]});
        }

        while (!mono_inc_stack.empty())
        {
            pair<int, int> top = mono_inc_stack.top();
            mono_inc_stack.pop();
            maxArea = max(maxArea, static_cast<int>(top.second * (heights.size() - top.first)));
        }

        return maxArea;
    }
};

int main()
{
    auto sol = new Solution();
    // vector<vector<int>> test = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<int> test = {2, 1, 5, 6, 2, 3};
    cout << sol->largestRectangleArea(test);
    // sol->partition(test, 0, test.size(), 3);
    // cout << sol->findKthLargest(test, 4) << endl;

    // vector<vector<int>> test = {
    //     {1, 4},
    //     {2, 3},
    // };

    // auto result = sol->merge(test);
    // for (auto res : result)
    // {
    //     cout << "[ ";
    // for (auto r : test)
    // {
    //     cout << r << ", ";
    // }
    // //     cout << "]";
    // //     cout << endl;
    // // }
    return 0;
}