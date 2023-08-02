#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack_arr;
        vector<char> opening_arr = {'(',
                                    '[',
                                    '{'};
        vector<char> closing_arr = {')',
                                    ']',
                                    '}'};

        for (char c : s)
        {
            if (find(opening_arr.begin(), opening_arr.end(), c) != opening_arr.end())
            {
                stack_arr.push(c);
            }
            else if (
                find(closing_arr.begin(), closing_arr.end(), c) != closing_arr.end()

                && !stack_arr.empty())
            {
                char top_elemnet = stack_arr.top();
                if (c == ')' && top_elemnet == '(')
                {
                    stack_arr.pop();
                }
                else if (
                    c == ']' && top_elemnet == '[')
                {
                    stack_arr.pop();
                }
                else if (
                    c == '}' && top_elemnet == '{')
                {
                    stack_arr.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return stack_arr.empty();
    }
};

int main()
{
    auto sol = Solution();
    string test = "]";
    auto result = sol.isValid(test);
    if (result)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    cout << endl;

    return 0;
}