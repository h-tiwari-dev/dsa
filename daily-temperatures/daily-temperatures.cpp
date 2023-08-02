#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> _dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> result;

        for (int i = 0; i < temperatures.size(); i++)
        {
            int check_value = temperatures[i];
            bool flag = false;

            for (int j = i; j < temperatures.size(); j++)
            {
                if (temperatures[i] < temperatures[j])
                {
                    result.push_back(j - i);
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                result.push_back(0);
            }
        }
        return result;
    }

    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> stack_arr;

        for (int i = 0; i < temperatures.size(); i++)
        {
            bool flag = false;
            if (stack_arr.empty() || stack_arr.top().first >= temperatures[i])
            {
                stack_arr.push(pair<int, int>{temperatures[i], i});
            }
            while (!stack_arr.empty() && stack_arr.top().first < temperatures[i])
            {
                flag = true;
                result[stack_arr.top().second] = i - stack_arr.top().second;
                stack_arr.pop();
            }
            if (flag)
            {
                stack_arr.push(pair<int, int>{temperatures[i], i});
            }
        }
        return result;
    }
};
int main()
{
    auto sol = Solution();
    vector<int> test = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
    auto result = sol.dailyTemperatures(test);

    for (auto res : result)
    {
        cout << res << ", ";
    }

    cout << endl;

    return 0;
}