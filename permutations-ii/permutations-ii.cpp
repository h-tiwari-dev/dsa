#include <set>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> result;
        set<int> mem_values;
        vector<int> curr_value;

        solve(nums, result, curr_value, mem_values);
        vector<vector<int>> real_result(result.begin(), result.end());
        return real_result;
    }

    void solve(
        vector<int> &nums,
        set<vector<int>> &result,
        vector<int> curr_value,
        set<int> &mem_values)
    {
        if (curr_value.size() == nums.size())
        {
            result.insert(curr_value);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (mem_values.find(i) == mem_values.end())
            {
                curr_value.push_back(nums[i]);
                mem_values.insert(i);
                solve(nums, result, curr_value, mem_values);
                curr_value.pop_back();
                mem_values.erase(i);
            }
        }
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test({1, 1, 2});
    auto res = sol->permuteUnique(test);

    for (auto r : res)
    {
        for (auto i : r)
        {
            cout << i << ", ";
        }
        cout << " \n";
    }
    return 0;
}