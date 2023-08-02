#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int curMin = 1;
        int curMax = 1;
        int result = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                curMax = 1;
                curMin = 1;
            }
            else
            {
                int tempMax = nums[i] * curMax;
                curMax = max(max(nums[i] * curMax, nums[i] * curMin), nums[i]);
                curMin = min(min(tempMax, nums[i] * curMin), nums[i]);
                result = max(curMax, result);
            }
        }
        return result;
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test = {2, 3, -2, 4};
    cout << sol->maxProduct(test);
    return 0;
}