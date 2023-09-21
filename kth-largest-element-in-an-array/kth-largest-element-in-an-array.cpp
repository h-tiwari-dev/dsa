#include <bitset>
#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> data;
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test = {3, 2, 1, 5, 6, 4};
    auto data = sol->findKthLargest(test, 2);
    cout << data;
    return 0;
}