#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        backTrace(result, candidates, {}, target, 0, 0);
        return result;
    }

    void backTrace(vector<vector<int>> &result, vector<int> &data, vector<int> temp_data, int target, int index, int sum)
    {
        if (sum > target)
            return;

        if (sum == target)
        {
            result.push_back(temp_data);
            return;
        }

        for (int i = index; i < data.size(); i++)
        {
            temp_data.push_back(data[i]);
            sum += data[i];
            backTrace(result, data, temp_data, target, i, sum);
            temp_data.pop_back();
            sum -= data[i];
        }
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test = {2, 3, 5};
    auto data = sol->combinationSum(test, 8);

    for (auto res : data)
    {
        cout << "[ ";
        for (auto r : res)
        {
            cout << r << ", ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}