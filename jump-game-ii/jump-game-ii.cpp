#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int result = 0;
        int left = 0, right = 0;

        while (right < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = left; i < right + 1; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            left = right + 1;
            right = farthest;
            result += 1;
        }

        return result;
    }
};

int main()
{
    vector<int> test{2, 3, 0, 1, 4};
    Solution *sol = new Solution();
    cout << sol->jump(test);
    return 0;
}
