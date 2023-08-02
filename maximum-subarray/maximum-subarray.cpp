#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(), INT_MIN);

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                dp[i] = nums[i];
            }
            else
            {
                if (nums[i] > (nums[i] + dp[i - 1]))
                {
                    dp[i] = nums[i];
                }
                else
                {
                    dp[i] = nums[i] + dp[i - 1];
                }
            }
        }
        auto res = max_element(dp.begin(), dp.end());

        return *res;
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sol->maxSubArray(test);
    return 0;
}