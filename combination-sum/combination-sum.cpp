#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        solve(candidates, target, {}, result, 0, 0);
        return result;
    }
    int solve(vector<int> &candidates, int target, vector<int> currResult, vector<vector<int>> &result, int currentSum, int startIndex)
    {
        if (currentSum > target)
        {
            return false;
        }
        for (int i = startIndex; i < candidates.size(); i++)
        {
            currResult.push_back(candidates[i]);
            if (solve(candidates, target, currResult, result, currentSum + candidates[i], i))
            {
                result.push_back(currResult);
            }
            currResult.pop_back();
        }
        if (currentSum == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test = {2, 3, 6, 7};
    auto result = sol->combinationSum(test, 7);
    for (auto res : result)
    {
        for (auto col : res)
        {
            cout << col << ", ";
        }
        cout << "\n";
    }
    return 0;
}
