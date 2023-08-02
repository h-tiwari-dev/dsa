#include <bits/stdc++.h>
#include <bitset>

using namespace std;
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        int arrow = 1;
        int end = points[0][1];

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > end)
            {
                arrow++;
                end = points[i][1];
            }
            else
            {
                end = min(end, points[i][1]);
            }
        }
        return arrow;
    }
};

int main()
{
    auto sol = new Solution();
    vector<vector<int>> test = {{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10}, {2, 9}, {0, 9}, {3, 9}, {0, 6}, {2, 8}};
    cout << sol->findMinArrowShots(test);
    return 0;
}