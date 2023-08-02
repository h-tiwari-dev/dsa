#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> dup_set = {};
        for (auto num : nums)
        {
            if (dup_set.find(num) == dup_set.end())
            {
                dup_set.insert(num);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    auto sol = new Solution();
    auto val = vector<int>{1, 2, 3};
    auto result = sol->containsDuplicate(val);
    if (result)
    {
        cout << "DUPLICATE";
    }
    else
    {
        cout << "NOT DUPLICATE";
    }
    return 0;
}