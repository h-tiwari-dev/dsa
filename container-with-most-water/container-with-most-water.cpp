#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = -1;
        int i(left), j(right);

        while (i < j)
        {
            if (height[i] > height[left])
            {
                left = i;
            }
            if (height[j] > height[right])
            {
                right = j;
            }
            if (height[left] <= height[right])
            {
                maxArea = max(maxArea, height[left] * abs(i - j));
            }
            else if (height[left] > height[right])
            {
                maxArea = max(maxArea, height[right] * abs(i - j));
            }
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxArea;
    }
};
int main()
{
    auto sol = new Solution();
    vector<int> test = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    auto result = sol->maxArea(test);
    cout << result;
    return 0;
}
