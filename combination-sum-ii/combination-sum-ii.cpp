#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test = {10, 1, 2, 7, 6, 1, 5};
    auto result = sol->combinationSum2(test, 8);
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
