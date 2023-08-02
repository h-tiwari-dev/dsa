#include <bits/stdc++.h>

using namespace std;

class NumArray
{
public:
    vector<int> nums;
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
    }

    int sumRange(int left, int right)
    {
        int sum = 0;
        for (int i = left; i <= right; i++)
        {
            sum += this->nums[i];
        }
        return sum;
    }
};
int main()
{
    vector<int> dat = {-2, 0, 3, -5, 2, -1};
    auto numArray = new NumArray(dat);
    cout << numArray->sumRange(0, 2); // return (-2) + 0 + 3 = 1
    cout << numArray->sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
    cout << numArray->sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
}