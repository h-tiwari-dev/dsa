#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string common_prefix;
        int smallest_string = INT_MAX;
        for (int i = 0; i < static_cast<int>(strs.size()); i++)
        {
            if (static_cast<int>(strs[i].size()) < smallest_string)
            {
                smallest_string = static_cast<int>(strs[i].size());
            }
        }

        int i = 0;
        bool flag = false;
        while (i < smallest_string)
        {
            char common_str = strs[0][i];
            for (int j = 0; j < static_cast<int>(strs.size()); j++)
            {
                if (common_str == strs[j][i])
                {
                    continue;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                return common_prefix;
            }
            else
            {
                common_prefix.push_back(common_str);
            }
            i++;
        }
        return common_prefix;
    }
};

int main()
{
    Solution *sol = new Solution();
    std::vector<string> test = {"flower", "flow", "flight"};
    std::cout
        << "Solution: " << sol->longestCommonPrefix(test);
    return 0;
}
