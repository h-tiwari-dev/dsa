#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        vector<vector<int>> result;

        int i = 1;
        int initial_value = intervals[0][0];
        int end_value = intervals[0][1];

        while (i < intervals.size())
        {
            if (end_value >= intervals[i][0])
            {
                if (end_value < intervals[i][1])
                {

                    end_value = intervals[i][1];
                }
            }
            else
            {
                result.push_back({initial_value, end_value});
                initial_value = intervals[i][0];
                end_value = intervals[i][1];
            }
            i++;
        }
        result.push_back({initial_value, end_value});
        return result;
    }
};

int main()
{
    auto sol = new Solution();
    vector<vector<int>> test = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> test = {
    //     {1, 4},
    //     {2, 3},
    // };

    auto result = sol->merge(test);
    for (auto res : result)
    {
        cout << "[ ";
        for (auto r : res)
        {
            cout << r << ", ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}