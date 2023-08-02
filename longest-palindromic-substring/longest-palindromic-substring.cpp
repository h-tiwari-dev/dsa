#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int s_size = s.length();
        string longest_string;
        int longest_string_len = INT_MIN;
        for (int i = 0; i < s_size; i++)
        {
            int l = i;
            int r = i;

            while (l >= 0 && r < s_size && s[l] == s[r])
            {
                if (longest_string_len < (r - l + 1))
                {
                    longest_string = s.substr(l, (r + 1) - l);
                    longest_string_len = r - l + 1;
                }
                l--;
                r++;
            }
            l = i;
            r = i + 1;

            while (l >= 0 && r < s_size && s[l] == s[r])
            {
                if (longest_string_len < (r - l + 1))
                {
                    longest_string = s.substr(l, (r + 1) - l);
                    longest_string_len = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return longest_string;
    }
};

int main()
{
    auto sol = Solution();
    string temp = "cbbd";
    cout << temp.substr(0, 3) << " " << temp[2] << " " << temp[3] << endl;
    cout << "Solution is: " << sol.longestPalindrome("bb");

    return 0;
}