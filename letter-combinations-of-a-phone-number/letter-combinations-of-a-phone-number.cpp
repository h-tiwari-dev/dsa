#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
        {
            return {};
        }
        map<char, vector<char>> digitsValue;

        digitsValue.insert(make_pair<int, vector<char>>('2', vector<char>({'a', 'b', 'c'})));
        digitsValue.insert(make_pair<int, vector<char>>('3', vector<char>({'d', 'e', 'f'})));
        digitsValue.insert(make_pair<int, vector<char>>('4', vector<char>({'g', 'h', 'i'})));
        digitsValue.insert(make_pair<int, vector<char>>('5', vector<char>({'j', 'k', 'l'})));
        digitsValue.insert(make_pair<int, vector<char>>('6', vector<char>({'m', 'n', 'o'})));
        digitsValue.insert(make_pair<int, vector<char>>('7', vector<char>({'p', 'q', 'r', 's'})));
        digitsValue.insert(make_pair<int, vector<char>>('8', vector<char>({'t', 'u', 'v'})));
        digitsValue.insert(make_pair<int, vector<char>>('9', vector<char>({'w', 'x', 'y', 'z'})));

        vector<vector<char>> candidates;

        for (auto digit : digits)
        {
            // auto val = digitsValue.find(digit).;
            candidates.push_back(digitsValue[digit]);
        }
        vector<vector<char>> results;

        solve(candidates, results, {}, digits.size(), 0, 0);

        vector<string> returnResult;

        for (auto res : results)
        {
            returnResult.push_back(string(res.begin(), res.end()));
        }
        return returnResult;
    }

    int solve(vector<vector<char>> &candidates, vector<vector<char>> &results, vector<char> temp_value, int n, int candidate_i, int candidate_j)
    {
        if (temp_value.size() == n)
        {
            results.push_back(vector(temp_value.begin(), temp_value.end()));
            return true;
        }
        if (temp_value.size() > n)
        {
            return false;
        }
        auto temp = candidates.size();
        if (candidate_i >= candidates.size())
        {
            return false;
        }
        if (
            candidate_j >= candidates[candidate_i].size())
        {

            return false;
        }

        // for (auto candidate : candidates)
        // {
        //     for (auto c : candidate)
        //     {
        // if (temp_value.find(candidates[candidate_i][candidate_j]) == temp_value.end())
        // {
        temp_value.push_back(candidates[candidate_i][candidate_j]);
        solve(candidates, results, temp_value, n, candidate_i + 1, 0);
        temp_value.pop_back();
        // }
        //     }
        // }
        // temp_value.insert(candidates[candidate_i][candidate_j]);
        solve(candidates, results, temp_value, n, candidate_i, candidate_j + 1);
        // temp_value.erase(candidates[candidate_i][candidate_j]);
        return true;
    }
};

int main()
{
    auto sol = new Solution();
    auto result = sol->letterCombinations("22");
    for (auto res : result)
    {
        cout << res << " ,";
    }
    return 0;
}
