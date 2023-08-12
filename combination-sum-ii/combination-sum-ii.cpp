#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, {}, result, 0, 0);
        // vector<vector<int>> res(result.begin(), result.end());
        return result;
    }

    int solve(vector<int> &candidates, int target, vector<int> currResult, vector<vector<int>> &result, int currentSum, int startIndex)
    {

        if (currentSum == target)
        {
            result.push_back(currResult);
            return true;
        }
        if (startIndex >= candidates.size())
        {
            return false;
        }
        if (currentSum <= target)
        {
            currResult.push_back(candidates[startIndex]);
            solve(candidates, target, currResult, result, currentSum + candidates[startIndex], startIndex + 1);
            currResult.pop_back();
        }
        int j = startIndex + 1;

        while (j < candidates.size() && candidates[j] == candidates[j - 1])
        {
            j += 1;
        }
        return solve(candidates, target, currResult, result, currentSum, j);
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test = {14, 6, 25, 9, 30, 20, 33, 34, 28, 30, 16, 12, 31, 9, 9, 12, 34, 16, 25, 32, 8, 7, 30, 12, 33, 20, 21, 29, 24, 17, 27, 34, 11, 17, 30, 6, 32, 21, 27, 17, 16, 8, 24, 12, 12, 28, 11, 33, 10, 32, 22, 13, 34, 18, 12};
    auto result = sol->combinationSum2(test, 27);
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
