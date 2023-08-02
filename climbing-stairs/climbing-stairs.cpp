#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(1);

        for (int i = 2; i <= n; i++)
        {
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        return dp[dp.size() - 1];
    }
};

int main()
{
    auto sol = new Solution();
    auto result = sol->climbStairs(3);
    cout << "Missing Number " << result << endl;
    return 0;
}