#include <bits/stdc++.h>
#include <bitset>

using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (minPrice > prices[i])
            {
                minPrice = prices[i];
            }

            if ((prices[i] - minPrice) > maxProfit)
            {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test = {7, 1, 5, 3, 6, 4};
    cout << sol->maxProfit(test);
    return 0;
}