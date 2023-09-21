#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int totalMaxValue = 0;
        int buyPrice = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > buyPrice)
            {
                totalMaxValue += prices[i] - buyPrice;
            }
            buyPrice = prices[i];
        }
        return totalMaxValue;
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test = {7, 6, 4, 3, 1};
    cout << sol->maxProfit(test);
    return 0;
}
