#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        set<int> mem_values;
        vector<int> curr_value;

        solve(nums, result, curr_value, mem_values);
        return result;
    }

    void solve(
        vector<int> &nums,
        vector<vector<int>> &result,
        vector<int> curr_value,
        set<int> mem_values)
    {
        if (curr_value.size() == nums.size())
        {
            result.push_back(curr_value);
        }
        for (auto num : nums)
        {
            if (mem_values.find(num) == mem_values.end())
            {
                curr_value.push_back(num);
                mem_values.insert(num);
                solve(nums, result, curr_value, mem_values);
                curr_value.pop_back();
                mem_values.erase(num);
            }
        }
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test({1, 2, 3});
    auto res = sol->permute(test);

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
