#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class Solution
{
public:
    int calculateOnes(int n, int k)
    {
        if (floor(n / 2) == 0)
        {
            return k;
        }
        return calculateOnes(floor(n / 2), n % 2);
    }

    vector<int> countBits(int n)
    {
        return {this->calculateOnes(1, 0)};
    }
};

int main()
{
    auto sol = new Solution();
    auto result = sol->countBits(2);
    for (auto res : result)
    {
        cout << "Missing Number " << res << endl;
    }
    return 0;
}