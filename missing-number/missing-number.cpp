#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int sigNum = accumulate(nums.begin(), nums.end(), 0, [](int acc, int x)
                                { return x ^ acc; });
        return sigNum;
    }
};

int main()
{
    auto sol = new Solution();
    auto val = vector<int>{4, 1, 2, 1, 2};
    auto result = sol->singleNumber(val);
    cout << "Missing Number " << result << endl;
    return 0;
}