#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> t_n{0, 0, 0};
        for (int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            if (nums[i] == 0)
            {
                t_n[0]++;
            }
            else if (nums[i] == 1)
            {
                t_n[1]++;
            }
            else if (nums[i] == 2)
            {
                t_n[2]++;
            }
        }
        int i = 0;
        int j = 0;
        while (j < t_n[0])
        {
            nums[i] = 0;
            i++;
            j++;
        }
        j = 0;
        while (j < t_n[1])
        {
            nums[i] = 1;
            i++;
            j++;
        }
        j = 0;
        while (j < t_n[2])
        {
            nums[i] = 2;
            i++;
            j++;
        }
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> test = {2, 0, 2, 1, 1, 0};
    sol->sortColors(test);

    for (int i = 0; i < static_cast<int>(test.size()); i++)
    {
        cout << test[i] << ", ";
    }
    cout << endl;
    return 0;
}
