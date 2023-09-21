#include <iostream>
#include <map>
#include <set>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        bool result = false;
        map<char, int> have_set;
        map<char, int> need_set;
        int have = 0;
        int need = 0;

        for (char c : s1)
        {
            need_set[c] += 1;
            need += 1;
        }

        int end = 0, s2_size = static_cast<int>(s2.size());

        while (end < s2_size)
        {
            if (need_set.find(s2[end]) == need_set.end())
            {
                if (static_cast<int>(have_set.size()) > 0)
                {
                    have_set.clear();
                }
                end += 1;
                have = 0;
                continue;
            }
            else if (need_set.find(s2[end]) != need_set.end() && (have_set[s2[end]] + 1) > need_set[s2[end]])
            {
                if (static_cast<int>(have_set.size()) > 0)
                {
                    have_set.clear();
                }
                have = 1;
                have_set[s2[end]] += 1;
            }
            else if (need_set.find(s2[end]) != need_set.end())
            {
                have_set[s2[end]] += 1;
                have += 1;
                if (have == need)
                {
                    return true;
                }
            }
            end += 1;
        }

        return result;
    }
};

int main()
{
    Solution *sol = new Solution();
    cout << "Result: " << sol->checkInclusion("adc", "dcda") << endl;
    return 0;
}
