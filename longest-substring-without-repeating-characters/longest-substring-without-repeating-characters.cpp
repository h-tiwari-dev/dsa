#include <iostream>
#include <set>
#include <deque>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        if (s.size() == 0)
            return 0;
        std::deque<char> new_vec;
        std::set<char> unq_set;
        int l = INT_MIN + 1;

        for (int i = 0; i < static_cast<int>(s.size()); i++)
        {
            char c = s[i];

            if (unq_set.find(c) == unq_set.end())
            {
                unq_set.insert(c);
                new_vec.push_back(c);
                if (static_cast<int>(unq_set.size()) > l)
                {
                    l = unq_set.size();
                }
            }
            else
            {
                while (new_vec.front() != c)
                {
                    auto temp1 = new_vec.front();
                    unq_set.erase(temp1);
                    new_vec.pop_front();
                }
                auto temp1 = new_vec.front();
                unq_set.erase(temp1);
                new_vec.pop_front();
                unq_set.insert(c);
                new_vec.push_back(c);
            }
        }

        return l;
    }
};

int main()
{
    Solution *sol = new Solution();
    std::cout << "Solution: " << sol->lengthOfLongestSubstring("abcabcbb");
    return 0;
}
