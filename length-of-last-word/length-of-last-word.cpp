#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int index = s.size() - 1;
        int lastWordSize = 0;
        bool flag = false;

        while (index >= 0)
        {
            if (s[index] == ' ' && flag)
            {
                return lastWordSize;
            }
            if (s[index] != ' ')
            {
                lastWordSize++;
                flag = true;
            }
            index--;
        }
        return lastWordSize;
    }
};

int main()
{
    auto sol = new Solution();
    auto result = sol->lengthOfLastWord("   fly me   to   the moon  ");
    cout << result;
    return 0;
}
