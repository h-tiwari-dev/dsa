#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        map<pair<int, int>, int> dp;
        return recursiveApproch(nums, target, 0, 0, dp);
    }

    int recursiveApproch(vector<int> &nums, int target, int index, int currSum, map<pair<int, int>, int> &dp)
    {
        if (dp.find({index, currSum}) != dp.end())
        {
            return dp[{index, currSum}];
        }
        if (index >= nums.size())
        {
            if (currSum == target)
            {
                return 1;
            }
            return 0;
        }

        int pos = recursiveApproch(nums, target, index + 1, currSum + nums[index], dp);
        int neg = recursiveApproch(nums, target, index + 1, currSum - nums[index], dp);

        int result = pos + neg;

        dp[{index, currSum}] = result;

        return result;
    }
};
int main()
{
    auto sol = new Solution();
    vector<int> test = {1, 1, 1, 1, 1};
    auto result = sol->findTargetSumWays(test, 3);
    cout << result;
    return 0;
}
