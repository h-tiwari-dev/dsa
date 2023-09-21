#include <bitset>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = INT_MIN;
        int heightSize = static_cast<int>(heights.size());
        stack<pair<int, int>> mono_inc_arr;
        int start;

        for (int i = 0; i < heightSize; i++)
        {
            // loop over it and check if this
            start = i;
            while (!mono_inc_arr.empty() && mono_inc_arr.top().second > heights[i])
            {
                pair<int, int> top = mono_inc_arr.top();
                mono_inc_arr.pop();
                maxArea = max(maxArea, top.second * (i - top.first));
                start = top.first;
            }
            mono_inc_arr.push({start, heights[i]});
        }

        while (!mono_inc_arr.empty())
        {
            pair<int, int> top = mono_inc_arr.top();
            mono_inc_arr.pop();
            maxArea = max(maxArea, top.second * (heightSize - top.first));
        }

        return maxArea == INT_MIN ? 0 : maxArea;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> test = {3, 2, 3, 3};
    cout << sol->largestRectangleArea(test);
    return 0;
}
