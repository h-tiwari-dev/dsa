#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        vector<char> curr_sum;
        solve(result, curr_sum, 0, 0, n);

        return result;
    }

    void solve(vector<string> &results, vector<char> &curr_sum, int curr_open_brac, int curr_closed_brac, int total_brac_allowed)
    {
        if (curr_closed_brac > curr_open_brac)
        {
            return;
        }
        if (curr_closed_brac > total_brac_allowed || curr_open_brac > total_brac_allowed)
        {
            return;
        }
        if (curr_closed_brac == total_brac_allowed && curr_open_brac == total_brac_allowed)
        {
            string char_to_s(curr_sum.begin(), curr_sum.end());
            results.push_back(char_to_s);
            return;
        }

        curr_sum.push_back('(');
        solve(results, curr_sum, curr_open_brac + 1, curr_closed_brac, total_brac_allowed);
        curr_sum.pop_back();

        curr_sum.push_back(')');
        solve(results, curr_sum, curr_open_brac, curr_closed_brac + 1, total_brac_allowed);
        curr_sum.pop_back();
    }
};

int main()
{
    auto sol = new Solution();
    auto res = sol->generateParenthesis(3);

    for (auto r : res)
    {
        cout << r << ", ";
    }
    return 0;
}