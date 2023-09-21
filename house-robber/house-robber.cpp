#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp;
        int numsSize = static_cast<int>(nums.size());

        if (numsSize == 0)
        {
            return 0;
        }
        else if (numsSize == 1)
        {
            return nums[0];
        }
        else if (numsSize == 2)
        {
            return max(nums[0], nums[1]);
        }
        else
        {
            dp.push_back(nums[0]);
            dp.push_back(max(nums[0], nums[1]));
        }

        for (int i = 2; i < numsSize; i++)
        {
            dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
        }

        for (auto a : dp)
        {
            cout << a << ", ";
        }
        cout << endl;
        int maxValue = *max_element(dp.begin(), dp.end());
        return maxValue;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> test{6, 3, 10, 8, 2, 10, 3, 5, 10, 5, 3};

    cout << sol->rob(test);

    return 0;
}
