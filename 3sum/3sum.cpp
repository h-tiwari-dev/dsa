#include<set>
#include<vector>
#include<iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        set<vector<int> > result;
        vector<vector<int> > return_value;
        int j, k;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            j = i + 1;
            k = nums.size() - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    result.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        for (auto temp : result)
        {
            return_value.push_back(temp);
        }
        return return_value;
    }
};

int main()
{
    auto sol = new Solution();
    vector<int> test = {-1, 0, 1, 2, -1, -4};

    auto result = sol->threeSum(test);
    for (auto res : result)
    {
        for (auto r : res)
        {
            cout << r << ", ";
        }
        cout << endl;
    }
    return 0;
}