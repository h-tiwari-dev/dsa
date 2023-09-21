#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        vector<int> nums;

        int i = 0;
        while (i < (static_cast<int>(s.size())))
        {
            if (i < (static_cast<int>(s.size()) - 1) && s[i + 1] == '0' && s[i] != '0')
            {
                // cout << i << " " << s.substr(i, i + 1) << endl;
                nums.push_back(stoi(s.substr(i, i + 1)));
                i++;
            }
            else
            {
                int val = int(s[i]) - '0';
                if (val == 0)
                {
                    return 0;
                }
                nums.push_back(val);
            }
            i++;
        }

        vector<int> dp;
        int numsSize = static_cast<int>(nums.size());
        dp.push_back(1);

        for (int j = 1; j < numsSize; j++)
        {
            if (nums[j] <= 6 && nums[j - 1] <= 2)
            {
                dp.push_back(dp[j - 1] + 1);
            }
        }

        cout << s << endl;
        for (auto a : nums)
        {
            cout << a << ", ";
        }
        cout << endl;
        for (auto a : dp)
        {
            cout << a << ", ";
        }
        cout << "\n----\n";

        return dp.back();
    }
};

int main()
{
    Solution *sol = new Solution();

    // cout << sol->numDecodings("11106");
    // cout << sol->numDecodings("12");
    // cout << sol->numDecodings("226");
    // cout << sol->numDecodings("06");
    // cout << sol->numDecodings("10");
    // cout << sol->numDecodings("00");
    // cout << sol->numDecodings("2101");
    cout << sol->numDecodings("1201234");

    return 0;
}
